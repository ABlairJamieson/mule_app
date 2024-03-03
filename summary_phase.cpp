
#include "summary_phase.hpp"

#include "picosystem.hpp"

using namespace picosystem;

void SummaryPhase::init(){
  phase_completed = false;
}



void SummaryPhase::update( unsigned tick){
  if (pressed(A)){
    if (called){
      phase_completed = true;
      called = false;
    } else {
      called = true;
    }
  }
}

void SummaryPhase::draw( unsigned tick ){
  pen(10, 10, 10);
  std::string s;
  if (get_phase()==FINALSUMMARY_PHASE) s = "Final Summary Phase ";
  else s = "Summary Phase ";
  s += "(press A to continue)";
  text( s , 8, 10 );
  std::string s2 = "Turn " + std::to_string(turn);
  text( s2, 8, 20 );
}
