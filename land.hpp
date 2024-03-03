#ifndef _land_hpp_
#define _land_hpp_

#include <array>
#include <random>


enum ResourceType {NO_MULE,FOOD,ENERGY,SMITHORE,CRYSTITE};

const unsigned LAND_NX = 9;
const unsigned LAND_NY = 5;
const unsigned LAND_N = LAND_NX * LAND_NY;

/// @brief Convert x,y location on screen to a unique id number
/// @param x horizontal location on screen
/// @param y vertical location on screen
/// @return id number
unsigned land_get_id( unsigned x, unsigned y);

/// @brief Convert land id to an x, y location on screen
/// @param id land id number
/// @param x horizontal location on screen
/// @param y vertical location on screen
void land_get_xy( unsigned id , unsigned& x, unsigned& y );

/// @brief Class to hold information about a land tile
/// Initialize with an id giving its location
class Land{
    public:

    /// @brief Initialize land tile properties
    /// @param aid        Unique id (location) of property
    /// @param ahasriver  Is it a river location
    /// @param amountains Number of mountains 0,1,2,3
    /// @param acrystite  Crystite level 0, 1, 2, 3, 4
    Land(unsigned aid=0, bool ahasriver=false, unsigned amountains=0, unsigned acrystite=0) : 
        id(aid), hasriver(ahasriver), mountains(amountains), crystite(acrystite) { } ;

    /// @brief Get mean number of production for this land and mule type
    /// @return number of dots of production
    unsigned get_dots(ResourceType m) const;

    // set methods
    void set_id( unsigned aid) {id=aid;}
    void set_hasriver( bool ahasriver ) { hasriver = ahasriver; }
    void set_mountains( unsigned amountains ) { mountains = amountains; }
    void set_crystite( unsigned acrystite ) { crystite = acrystite; }

    // get methods
    unsigned get_id() const { return id; }
    bool     get_hasriver() const { return hasriver; }
    unsigned get_mountains() const { return mountains; }
    unsigned get_crystite() const { return crystite; }

    private:

    unsigned id;
    bool     hasriver;
    unsigned mountains;
    unsigned crystite;
 
};

extern std::array< Land, LAND_N > land_plots;

/// @brief Call this to set up the land plots (initialize the array land_plots)
void land_initialize_plots();


#endif