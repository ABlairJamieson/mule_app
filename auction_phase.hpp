#ifndef _auction_phase_hpp_
#define _auction_phase_hpp_

#include "game_phase.hpp"
#include "land.hpp"

class AuctionPhase : public GamePhase {
    public:
    AuctionPhase(unsigned t, ResourceType r ) : GamePhase(AUCTION_PHASE), called(false), turn(t), type(r) {};

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    private:
    bool     called;
    unsigned turn;
    ResourceType type;
};

#endif
