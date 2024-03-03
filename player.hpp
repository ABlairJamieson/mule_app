#ifndef _player_hpp_
#define _player_hpp_

#include "land.hpp"
#include <vector>
#include <array>
#include <string>

// define the races you can play
enum RaceType {
   MECHTRON, GOLLUMER, PACKER,
   BONZOID,            SPHEROID,
   FLAPPER,  LEGGITE,  HUMANOID };

// a place to define and store our settler races
struct race_t {
  int id;
  std::string name;
};

extern std::array<race_t, 8> races; 
  
class Player{
    public:

    /// @brief Define a player
    /// @param mo starting money
    /// @param fo starting number of units of food
    /// @param en starting number of units of energy
    /// @param sm starting number of units of smithore
    /// @param cr starting number of units of crystite
    /// @param r  player race
    Player( unsigned mo=1200, unsigned fo=4, unsigned en=2, unsigned sm=0, unsigned cr=0, RaceType r=MECHTRON ) :
     money(mo), food(fo), energy(en), smithore(sm), crystite(cr), race(r) {};

    void init(){
        money=1200; food=4; energy=4; smithore=0; crystite=0; race=MECHTRON;
        land.clear();
    }

    // set and get methods
    void     set_money( unsigned mo ) { money=mo;}
    unsigned get_money() const { return money; }

    void     set_food( unsigned fo ) { food=fo; }
    unsigned get_food() const { return food; }

    void     set_energy( unsigned en ) { energy=en;}
    unsigned get_energy() const { return energy; }

    void     set_smithore( unsigned sm ) { smithore=sm;}
    unsigned get_smithore() const { return smithore; }

    void     set_crystite( unsigned cr ) { crystite=cr;}
    unsigned get_crystite() const { return crystite; }
    
    // add land title
    void     add_land( unsigned id ) { land.push_back( id ); }

    // get list of land
    const std::vector<unsigned>& get_land() const { return land; }    

    private:

    unsigned money;
    unsigned food;
    unsigned energy;
    unsigned smithore;
    unsigned crystite;
    RaceType race;
    std::vector<unsigned> land;
};

extern std::array<Player,4> players;

void init_players();

#endif