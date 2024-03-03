
#include "game_engine.hpp"

void GameEngine::init(unsigned start){
    for (unsigned iphase=start; iphase<phases.size(); ++iphase ){
        phases[iphase]->init();
    }
}

void GameEngine::update(unsigned tick){
    phases[curphase]->update( tick );
}

void GameEngine::draw(unsigned tick){
    phases[curphase]->draw( tick );
}