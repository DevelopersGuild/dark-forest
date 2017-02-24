#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include "Walls.h"
#include <iostream>
#include <string>

class MainPlayer
{
private:
    //int cposition[4][2]; // current posistion
    int COLS = 31;
     sf::Texture texture;
     sf::Sprite mainCh;
    
public:
    
    
    // Make a constructor that sets the origin of the player at {-300,0}
     MainPlayer();
    
    // Make a function that updates the position after moving a specific direction
     void MovePlayer(int ROWS, bool ifwall);
     void draw(sf::RenderWindow &window)
     {
          window.draw(mainCh);
     }
      
};
#endif
