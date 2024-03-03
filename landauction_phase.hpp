#ifndef _landauction_phase_hpp_
#define _landauction_phase_hpp_

#include "game_phase.hpp"

class LandauctionPhase : public GamePhase {
    public:
    LandauctionPhase( unsigned t ) : GamePhase( LANDAUCTION_PHASE ), called(false), turn(t) {};

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    private:
    bool     called;
    unsigned turn;
};

#endif
