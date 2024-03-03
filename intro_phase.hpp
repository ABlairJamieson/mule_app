#ifndef _intro_phase_hpp_
#define _intro_phase_hpp_

#include "game_phase.hpp"

enum GameType { BEGINNER, STANDARD, TOURNAMENT };

class IntroPhase : public GamePhase {
    public:
    IntroPhase() : GamePhase(INTRO_PHASE), called(false) {};

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    GameType get_gametype() const { return gametype; }

    private:
    bool     called;
    GameType gametype;
};

#endif
