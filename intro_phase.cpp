
#include "intro_phase.hpp"

#include "picosystem.hpp"

using namespace picosystem;

void IntroPhase::init(){
    gametype = BEGINNER;
    phase_completed = false;
}


void IntroPhase::update( unsigned tick){
  if (pressed(UP)){
    switch (gametype){
      case BEGINNER:
        gametype = STANDARD;
        break;
      case STANDARD:
        gametype = TOURNAMENT;
        break;
      case TOURNAMENT:
        gametype = BEGINNER;
        break;
    }; 
  }
  if (pressed(DOWN)){
    switch (gametype){
        case BEGINNER:
            gametype = TOURNAMENT;
            break;
        case STANDARD:
            gametype = BEGINNER;
            break;
        case TOURNAMENT:
            gametype = STANDARD;
            break;
    }; 
  }
    
  if (pressed(A)){
    if (called){
      phase_completed = true;
      called = false;
    } else {
      called = true;
    }
  }
}

void IntroPhase::draw( unsigned tick ){
  pen(10, 10, 10);
  text( "Pick game type (UP/DOWN)", 8, 10 );
  std::string str_type ="Choice: ";
  switch (gametype){
    case BEGINNER:
        str_type += "Beginner";
        break;
    case STANDARD:
        str_type += "Standard";
        break;
    case TOURNAMENT:
        str_type += "Tournament";
  }
  text( str_type , 8, 30);
}
