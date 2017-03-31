//
//  Monster.hpp
//  SampleGame
//
//  Created by Deepti 1/27/2017
//  Edited by Ye Eun Myung on 03/03/2017
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//
#ifndef Monster_hpp
#define Monster_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include "Block.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
class Monster
{
private:
     sf::Texture texture;
     sf::Sprite monster;
     std::vector<std::vector<Block*>> boolean;
     bool isMove = false;
     bool goDown = true;
     bool goUp = true;
     bool goLeft = true;
     bool goRight = true;

public:
     Monster();
     void setInitPosition(std::vector<std::vector<Block*>> block); //set initial position
     void checkBoundaries(std::vector<std::vector<Block*>> block, sf::Vector2f mainChPos, bool isMainChMove);
     void findPath(std::vector<std::vector<Block*>> block, sf::Vector2f mainChPos, bool isMainChMove);
     void moveOrder(std::vector<std::vector<Block*>> block, int num, int i, int j);
     void draw(sf::RenderWindow &window) { window.draw(monster); }
};
#endif
