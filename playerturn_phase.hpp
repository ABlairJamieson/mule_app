#ifndef _playerturn_phase_hpp_
#define _playerturn_phase_hpp_

#include "game_phase.hpp"

class PlayerturnPhase : public GamePhase {
    public:
    PlayerturnPhase( unsigned t, bool c ) : GamePhase(PLAYERTURN_PHASE), called(false), turn(t), usecrystite(c) {};

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    private:
    bool     called;
    unsigned turn;
    bool     usecrystite;
};

#endif
