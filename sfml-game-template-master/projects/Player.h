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
public:

    // Make a constructor that sets the position of the character
     MainPlayer();
    
    //updates the position after moving a specific direction
     void MovePlayer(std::vector<std::vector<Block*>> block);
     //return true if the main character moved
     bool isMove(){ return move; }
     void draw(sf::RenderWindow &window) { window.draw(mainCh); }
     bool isLive() { return live; }
      
};
#endif
