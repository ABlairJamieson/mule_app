#ifndef _production_phase_hpp_
#define _production_phase_hpp_

#include "game_phase.hpp"

class ProductionPhase : public GamePhase {
    public:
    ProductionPhase(unsigned t, bool c) : GamePhase(PRODUCTION_PHASE), called(false), turn(t), usecrystite(c) {};

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    private:
    bool     called;
    unsigned turn;
    bool     usecrystite;
};

#endif
