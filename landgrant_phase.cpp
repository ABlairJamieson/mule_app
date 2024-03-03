
#include "landgrant_phase.hpp"

#include "picosystem.hpp"

using namespace picosystem;

void LandgrantPhase::init(){
  phase_completed = false;
}


void LandgrantPhase::update( unsigned tick){


  if (pressed(A)){
    if (called){
      phase_completed = true;
      called = false;
    } else {
      called = true;
    }
  }
}

void LandgrantPhase::draw( unsigned tick ){
  pen(10, 10, 10);
  text( "Land grant phase (press A to continue)", 8, 10 );
  std::string s2 = "Turn " + std::to_string(turn);
  text( s2, 8, 20 );
}
