
#include "character_phase.hpp"

#include "picosystem.hpp"

using namespace picosystem;

std::array<charcolors_t, 4> charcolors = {{
  {CHAR_BLUE,   "Blue",   rgb(0,0,255,15) },
  {CHAR_RED,    "Red",    rgb(255,0,0,15) },
  {CHAR_GREEN,  "Green",  rgb(0,255,0,15) },
  {CHAR_ORANGE, "Orange", rgb(255, 165, 0, 15) }
}};

void CharacterPhase::init(){
    phase_completed = false;
 }


void CharacterPhase::update( unsigned tick){
  if (pressed(UP)){
    unsigned curcol = unsigned( color );
    curcol = (++curcol)%4;
    color = CharacterColor(curcol);
  }
  if (pressed(DOWN)){
    unsigned curcol = unsigned( color );
    if (curcol==0) {
      curcol = 3;
    } else { 
      --curcol;
    }
    color = CharacterColor(curcol);
  }
  if (pressed(RIGHT)){
    unsigned curchar = unsigned(race);
    curchar = (++curchar)%8;
    race = RaceType(curchar);
  }
  if (pressed(LEFT)){
    unsigned curchar = unsigned(race);
    if (curchar==0) curchar = 7;
    else --curchar;
    race = RaceType(curchar);
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

void CharacterPhase::draw( unsigned tick ){
  pen(10, 10, 10);
  text( "Pick color (UP/DOWN)", 8, 10 );
  text( "Pich race (LEFT/RIGHT)", 8, 20);
  text( "Press A to select", 8, 100);
  std::string str_race ="Race: ";
  str_race += races[race].name;
  text( str_race , 8, 30);
  std::string str_color = "Color: ";
  str_color += charcolors[color].name;
  pen( charcolors[color].color );
  text( str_color, 8, 40 );
  frect(8, 50, 40, 40);
}
