//
//  Map.hpp
//  SampleGame
//
//  Created by Margaret Patrick on 1/20/17.
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//

/* Map() 
* class is in charge of keeping the location of all "Blocks" within the game, 
* contains a 'grid' which assigns one block to each location of the game
* currently a 32*20 grid that contains 25 square pixil blocks
*/

//TODO: probably unnecceary to have a struct inside the class
#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>

#include "Block.hpp"

class Map{       
    public:
        struct _layout{
            const static int ROW = 20;
            const static int COL = 32;
            const static int BLO_WID = 25; // 25 by 25 size blocks
            Block* grid[ROW][COL];
        };
        
        void checker(); // creates a checkerboard pattern on the map, solely for testing
        
        _layout layout(){ return map; } //returns the map
        
    private:
        _layout map; // layout of the map
};

#endif /* Map_hpp */
