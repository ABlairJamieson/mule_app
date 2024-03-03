#ifndef _character_phase_hpp_
#define _character_phase_hpp_

#include "picosystem.hpp"
#include "game_phase.hpp"
#include "player.hpp"

using namespace picosystem;

enum CharacterColor {CHAR_BLUE, CHAR_RED, CHAR_GREEN, CHAR_ORANGE };

// a place to define and store our weapons
struct charcolors_t {
  int         id;
  std::string name;
  color_t     color;
};

extern std::array<charcolors_t, 4> charcolors;

class CharacterPhase : public GamePhase {
    public:
    CharacterPhase() : GamePhase(CHARACTER_PHASE), called(false), race(MECHTRON), color(CHAR_BLUE) {};

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    private:
    bool           called;
    RaceType       race;
    CharacterColor color;
};

#endif
