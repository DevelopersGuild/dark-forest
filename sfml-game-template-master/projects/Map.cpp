//
//  Map.cpp
//  SampleGame
//
//  Created by Margaret Patrick on 1/20/17.
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//

#include "Map.hpp"
#include "Block.hpp"
#include <iostream>



Map::Map(int row, int col, int block_width) : ROW(row) , COL(col) , BLO_WID(block_width){

    grid.resize(ROW);
    for (int i = 0; i < ROW; ++i) grid[i].resize(COL);
} 

/*checker()
* fills the layout with blocks of alternating color, a checker pattern.
* return: nothing
*/
void Map::checker(){
    sf::Color color = sf::Color::Green;
    int col = this->COL;
    int row = this->ROW;
    int blo_wid = this->BLO_WID;
    
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
        
            if (color == sf::Color::Green){
                color = sf::Color::Red;
            }
            else color = sf::Color::Green;
            
            this->grid[i][j] = new Block(color, j*blo_wid, i*blo_wid, blo_wid, true);
        }
        if (color == sf::Color::Green){
            color = sf::Color::Red;
        }
        else color = sf::Color::Green;
    }
}
