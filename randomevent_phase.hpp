#ifndef _randomevent_phase_hpp_
#define _randomevent_phase_hpp_

#include "game_phase.hpp"

class RandomeventPhase : public GamePhase {
    public:
    RandomeventPhase(unsigned t, bool c) : GamePhase(RANDOMEVENT_PHASE), called(false), turn(t), usecrystite(c) {};

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    private:
    bool     called;
    unsigned turn;
    bool     usecrystite;
};

#endif
