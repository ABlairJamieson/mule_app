
#include "playerturn_phase.hpp"

#include "picosystem.hpp"

using namespace picosystem;

void PlayerturnPhase::init(){
  phase_completed = false;
}


void PlayerturnPhase::update( unsigned tick){


  if (pressed(A)){
    if (called){
      phase_completed = true;
      called = false;
    } else {
      called = true;
    }
  }
}

void PlayerturnPhase::draw( unsigned tick ){
  pen(10, 10, 10);
  text( "Player turn phase (press A to continue)", 8, 10 );
  std::string s2 = "Turn " + std::to_string(turn);
  text( s2, 8, 20 );
}
