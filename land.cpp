
#include "land.hpp"
#include <vector>
#include <algorithm>


std::array< Land, LAND_N > land_plots;


unsigned land_get_id( unsigned x, unsigned y){
    return y*LAND_NX + x;
}

void land_get_xy( unsigned id , unsigned& x, unsigned& y ){
    x = id % LAND_NX;
    y = id / LAND_NX;
}

unsigned Land::get_dots(ResourceType m) const{
    unsigned dots = 0;
    switch (m){
    case NO_MULE:
        break;
    case FOOD:
        if (hasriver){
            dots = 4;
        } else if (mountains>0) {
            dots = 1;
        } else {
            dots = 2;
        }
        break;
    case ENERGY:
        if (hasriver){
            dots = 2;
        } else if (mountains>0){
            dots = 1;
        } else {
            dots = 3;
        }
        break;
    case SMITHORE: 
        dots = mountains+1;
        break;
    case CRYSTITE:
        dots = crystite;
        break;

    };
    return dots;
}


void land_initialize_plots(){
    std::default_random_engine rdev;

    // set unique ids and place river down center
    for (unsigned iy=0; iy<LAND_NY; ++iy){
        for (unsigned ix=0; ix<LAND_NX; ++ix){  
            unsigned curid = land_get_id( ix, iy );
            land_plots[curid].set_id( curid );
            if (ix == 2){
                land_plots[curid].set_hasriver( true );
            }
        }
    }

    // place mountains (3 are high, 3 are med, 3 are low)
    std::vector< unsigned > mntnlocs;
    std::uniform_int_distribution<unsigned> udist(0,LAND_NX*LAND_NY-1); //(inclusive, inclusive) 
    while ( mntnlocs.size() < 9 ){
        unsigned randomid = udist( rdev );
        unsigned ix=0,iy=0;
        land_get_xy(randomid,ix,iy);
        if (ix==2) continue; // skip river plots which are down center
        auto elem = std::find(std::begin(mntnlocs), std::end(mntnlocs), randomid);
        // When the element is not found, std::find returns the end of the range    
        if (elem == std::end(mntnlocs)) {
            mntnlocs.push_back(randomid);
        }
    }
    for (unsigned i=0; i<mntnlocs.size(); ++i){
        unsigned curid = mntnlocs[i];
        if (i<3){
            land_plots[curid].set_mountains(3);
        } else if (i<6){
            land_plots[curid].set_mountains(2);
        } else {
            land_plots[curid].set_mountains(1);
        }
    }

    // place crystite
    std::vector<unsigned> crlocs;
    while ( crlocs.size() < 3 ){
        unsigned randomid = udist(rdev);
        auto elem = std::find(std::begin(crlocs), std::end(crlocs), randomid);
        // When the element is not found, std::find returns the end of the range    
        if (elem == std::end(crlocs)) {
            crlocs.push_back(randomid);
        }
    }
    for ( unsigned i=0; i<crlocs.size(); ++i){
        unsigned crloc = crlocs[i];
        unsigned ix=0,iy=0;
        land_get_xy(crloc,ix,iy);
        for ( int x = -2; x<=2; ++x ){
            for ( int y = -2; y<=2; ++y){
                int xx = int(ix) + x;
                int yy = int(iy) + y;
                int crystite = 3 - abs(x) - abs(y);
                if (crystite>0){
                    if (xx>=0 && yy>=0 && xx<LAND_NX && yy<LAND_NY){
                        unsigned offsloc = land_get_id( unsigned(xx), unsigned(yy ));
                        if ( land_plots[offsloc].get_crystite() < unsigned(crystite) ) {
                            land_plots[offsloc].set_crystite( unsigned(crystite) );
                        }
                    }
                }
            }
        }
    }

}
    