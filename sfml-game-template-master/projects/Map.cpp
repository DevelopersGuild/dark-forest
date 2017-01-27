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



/*checker()
* fills the layout with blocks of alternating color, a checker pattern.
* return: nothing
*/
void Map::checker(){
    sf::Color color = sf::Color::Green;
    
    int col = this->map.COL;
    int row = this->map.ROW;
    int blo_wid = this->map.BLO_WID;
    
    for (int i = row - 1; i >= 0; --i){
        for (int j = col - 1; j >= 0; --j){
        
            if (color == sf::Color::Green){
                color = sf::Color::Red;
            }
            else color = sf::Color::Green;
            
            this->map.grid[i][j] = new Block(color, j*blo_wid, i*blo_wid, blo_wid);
        }
        if (color == sf::Color::Green){
            color = sf::Color::Red;
        }
        else color = sf::Color::Green;
    }
}
