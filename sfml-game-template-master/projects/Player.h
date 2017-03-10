//
//  Player.hpp
//  SampleGame
//
//  Created by Deepti 1/27/2017
//  Edited by Ye Eun Myung on 03/03/2017
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//
#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include "Walls.h"
#include "Block.h"
#include <string>
#include <iostream>
#include <vector>

class MainPlayer
{
private:
     sf::Texture texture;
     sf::Sprite mainCh;
     bool move;
     bool live; //only one life (for now)
     bool goal;
public:

    // Make a constructor that sets the position of the character
     MainPlayer();
    
    //updates the position after moving a specific direction
     void MovePlayer(std::vector<std::vector<Block*>> block);
     void checkGoal(std::vector<std::vector<Block*>> block);
     //return true if the main character moved
     bool isMove(){ return move; }
     bool isLive() { return live; }
     bool isGoal() { return goal; }
     void draw(sf::RenderWindow &window) { window.draw(mainCh); }
      
};
#endif
