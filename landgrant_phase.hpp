#ifndef _landgrand_phase_hpp_
#define _landgrand_phase_hpp_

#include "game_phase.hpp"

class LandgrantPhase : public GamePhase {
    public:
    LandgrantPhase( unsigned t ) : GamePhase(LANDGRANT_PHASE), called(false), turn(t) {};

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    private:
    bool     called;
    unsigned turn;
};

#endif
