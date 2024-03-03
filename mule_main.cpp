#include <math.h>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>

#include "picosystem.hpp"
#include "player.hpp"
#include "land.hpp"
#include "game_engine.hpp"
#include "intro_phase.hpp"
#include "character_phase.hpp"
#include "summary_phase.hpp"
#include "landgrant_phase.hpp"
#include "landauction_phase.hpp"
#include "playerturn_phase.hpp"
#include "production_phase.hpp"
#include "randomevent_phase.hpp"
#include "auction_phase.hpp"

using namespace picosystem;

voice_t blip;

GameEngine eng;

unsigned turn = 0;
unsigned current_phase = 0;


// game phases:
// 0 Intro page : pick game type : beginner, standard, tournament
// 1 Character page : pick color and pick race
// 2 Summary page 
// 3 Land grant
// 4 Land auction phase
// 5 Player turn phase
// 6 Production phase
// 7 Random event phase
// 8 Auction phase;
// return to summary page (some number of times, increment turn)
// 9 Final summary page (after defined number of turns)
// return to Intro page

void add_turn_phases( unsigned i, bool usecrystite){
  eng.add_phase( new SummaryPhase(i) );
  eng.add_phase( new LandgrantPhase(i) );
  eng.add_phase( new LandauctionPhase(i) );
  eng.add_phase( new PlayerturnPhase(i,usecrystite) );
  eng.add_phase( new ProductionPhase(i,usecrystite) );
  eng.add_phase( new RandomeventPhase(i,usecrystite) );
  eng.add_phase( new AuctionPhase(i,SMITHORE) );
  if (usecrystite){
    eng.add_phase( new AuctionPhase(i,CRYSTITE));
  }
  eng.add_phase( new AuctionPhase(i,ENERGY));
  eng.add_phase( new AuctionPhase(i,FOOD));
}

// initialise the world
void init() {
  init_players();
  land_initialize_plots();
  eng.add_phase( new IntroPhase() );
  eng.add_phase( new CharacterPhase() );
  eng.init();

  blip = voice(10, 10, 10, 10, 40, 2);
} 

// setup phases after intro page
void setup_turns( GameType t ){
  unsigned nturns = 6;
  bool     usecrystite = false;
  switch (t){
  case BEGINNER:
    break;
  case STANDARD:
    nturns = 10;
    break;
  case TOURNAMENT:
    nturns = 12;
    usecrystite = true;
    break;
  };
  // add the turn phases
  for (unsigned iturn = 0 ; iturn<nturns; ++iturn){
    add_turn_phases( iturn, usecrystite );    
  }
  // add the final summary phase
  eng.add_phase( new SummaryPhase(nturns,true) );

  // initialize all the phases (skip 0, 1 -- the intro and character choice)
  eng.init(2);
  
}


// process user input and update the world state
void update(uint32_t tick) {
  // check if current running phase completed
  if ( eng.get_phase()->is_complete() ){
    if (eng.get_phase()->get_phase() == INTRO_PHASE){
      IntroPhase * intro = static_cast< IntroPhase* >( eng.get_phase() );
      setup_turns( intro->get_gametype() );
    }
    if (eng.get_phase()->get_phase() == FINALSUMMARY_PHASE){
      eng.clear();
      current_phase = 0;
      eng.set_phase(0);
      init();
    } else {
      ++current_phase;
    }
  }
  eng.set_phase(current_phase);
  // run the current phase
  eng.update(tick);

}


// draw the world
void draw(uint32_t tick) {
  // clear the background
  alpha();
  pen(1, 1, 1);
  clear();
  
  eng.draw(tick);
}


