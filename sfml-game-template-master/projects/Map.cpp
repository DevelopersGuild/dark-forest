//
//  Map.cpp
//  SampleGame
//
//  Created by Margaret Patrick on 1/20/17.
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//

#include "Map.h"
#include "Block.h"
#include <iostream>

using namespace sf;

Map::Map(int row, int col, int block_width) : ROW(row) , COL(col) , BLO_WID(block_width){
    grid.resize(ROW);
    for (int i = 0; i < ROW; ++i) grid[i].resize(COL);
} 

/*checker()
* fills the map with ground texture
* return: nothing
*/
void Map::checker(){
     int testmap[20][25] = {
          { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
          { 0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1,0 },
          { 0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0 },
          { 0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0 },
          { 0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0 },
          { 0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,1,1,0 },
          { 0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0 },
          { 0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1,0 },
          { 0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0 },
          { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0 },
          { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0 },
          { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0 },
          { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0 },
          { 0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0 },
          { 0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,1,1,1,0 },
          { 0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
          { 0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0 },
          { 0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
          { 0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0 },
          { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
     };

     Texture* groundTexture = new Texture;
     groundTexture->loadFromFile(resourcePath() + "assets/ground.jpg");

     Texture* treeTexture = new Texture;
     treeTexture->loadFromFile(resourcePath() + "assets/tree.jpg");

     for (int i = 0; i < ROW; ++i) {
          for (int j = 0; j < COL; ++j) {
               if (testmap[i][j] == 0) grid[i][j] = new Block(groundTexture, j*BLO_WID, i*BLO_WID, BLO_WID, true);
               if (testmap[i][j] == 1) grid[i][j] = new Block(treeTexture, j*BLO_WID, i*BLO_WID, BLO_WID, false);
          }
     }

}
