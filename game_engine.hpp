#ifndef _game_engine_hpp_
#define _game_engine_hpp_

#include "game_phase.hpp"
#include <vector>

class GameEngine {
    public:
    GameEngine() : curphase(0) {};

    void add_phase( GamePhase* p ){ phases.push_back(p); }

    void init(unsigned start=0);
    void update(unsigned tick);
    void draw(unsigned tick);

    void clear(){ 
        for (auto phase : phases){
            delete phase;
        }    
        phases.clear(); 
    }

    void set_phase( unsigned p ){ curphase = p; }
    GamePhase* get_phase() { return phases[curphase]; }

    private:

    unsigned curphase;
    std::vector<GamePhase*> phases;


};


#endif