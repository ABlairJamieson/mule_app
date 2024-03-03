#ifndef _summary_phase_hpp_
#define _summary_phase_hpp_

#include "game_phase.hpp"

class SummaryPhase : public GamePhase {
    public:
    SummaryPhase(unsigned t, bool f=false ) : GamePhase(SUMMARY_PHASE), called(false), turn(t), final(f) {
      if (final) type = FINALSUMMARY_PHASE;
    };

    void init();
    void update( unsigned tick );
    void draw( unsigned tick );

    private:
    bool     called;
    unsigned turn;
    bool     final;
};

#endif
