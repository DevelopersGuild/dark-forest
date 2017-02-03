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
* currently a 32*20 grid that contains 25 square pixil blocks is recomended
*/

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <vector>
#include "Block.h"

using namespace std;
class Map{       
    public:
        /* constructor
        *@param: number of rows in the map
        *@param: number of columbs in the map
        *@param: width in pixels of a single block
        */
        Map(int row, int col, int block_width); // default constructor, resizes grid
        
        /* checker()
        * creates a checkerboard pattern on the map, solely for testing
        */
        void checker();
        
        vector<vector<Block*> > layout(){ return grid; } //returns the map
        int row(){ return ROW; } //returns the number of rows
        int col(){ return COL; } // returns the number of columbs
        int blo_wid(){ return BLO_WID; } // returns the width in pixels of each block
        
    private:
        Block** map; // layout of the map
        const int ROW;
        const int COL;
        const int BLO_WID; // 25 by 25 size blocks
        
        vector<vector<Block*> > grid; //vector of the grid
};

#endif /* Map_hpp */
