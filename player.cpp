
#include "player.hpp"
#include <array>

std::array<race_t, 8> races = {{
  {MECHTRON, "Mechtron"},
  {GOLLUMER, "Gollumer"},
  {PACKER,   "Packer"},
  {SPHEROID, "Spheroid"},
  {FLAPPER,  "Flapper"},
  {LEGGITE,  "Leggite"},
  {HUMANOID, "Humanoid"}  
}};

std::array<Player,4> players;

void init_players(){
    for (auto &player : players){
        player.init();
    }
}

