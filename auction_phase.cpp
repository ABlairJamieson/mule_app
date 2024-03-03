
#include "auction_phase.hpp"

#include "picosystem.hpp"

using namespace picosystem;

void AuctionPhase::init(){
  phase_completed = false;
}


void AuctionPhase::update( unsigned tick){


  if (pressed(A)){
    if (called){
      phase_completed = true;
      called = false;
    } else {
      called = true;
    }
  }
}

void AuctionPhase::draw( unsigned tick ){
  pen(10, 10, 10);
  std::string s = "Auction Phase ";
  switch(type){
    case FOOD:
      s += "Food";  break;
    case ENERGY:
      s += "Energy"; break;
    case SMITHORE:
      s += "Smithore"; break;
    case CRYSTITE:
      s += "Crystite"; break;
  };
  s += " (press A to continue)";
  text( s, 8, 10 );
  std::string s2 = "Turn " + std::to_string(turn);
  text( s2, 8, 20 );
}
