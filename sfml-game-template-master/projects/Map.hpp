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
#include <vector>
#include "Block.hpp"

using namespace std;
class Map{       
    public:
        Map(int row, int col, int block_width); // default constructor, resizes grid
        
        void checker(); // creates a checkerboard pattern on the map, solely for testing
        
        vector<vector<Block*> > layout(){ return grid; } //returns the map
        int row(){ return ROW; }
        int col(){ return COL; }
        int blo_wid(){ return BLO_WID; }
        
    private:
        Block** map; // layout of the map
        const int ROW;
        const int COL;
        const int BLO_WID; // 25 by 25 size blocks
        
        vector<vector<Block*> > grid;
};

#endif /* Map_hpp */
