#ifndef _game_phase_hpp_
#define _game_phase_hpp_

enum GamePhases {
  INTRO_PHASE, 
  CHARACTER_PHASE, 
  SUMMARY_PHASE, 
  LANDGRANT_PHASE, 
  LANDAUCTION_PHASE, 
  PLAYERTURN_PHASE,
  PRODUCTION_PHASE,
  RANDOMEVENT_PHASE,
  AUCTION_PHASE,
  FINALSUMMARY_PHASE
  };

/// @brief Abstract base class for game phases
class GamePhase {
    public:
    GamePhase( GamePhases t=INTRO_PHASE ) : type(t) { phase_completed=false; };

    virtual void init() = 0;
    virtual void update( unsigned tick ) = 0;
    virtual void draw( unsigned tick ) = 0;

    unsigned get_phase() const { return type; }
    void set_phase( GamePhases t ){ type = t; }

    bool is_complete() const { return phase_completed; }

    protected:
    GamePhases type;
    bool phase_completed;
};

#endif