#include "Walls.h"
#include <iostream>
#include <string>

class MainPlayer : Walls
{
private:
    int cposition[4][2]; // current posistion
    int COLS = 31;
    
public:
    
    
    // Make a constructor that sets the origin of the player at {-300,0}
    Mainplayer()
    {
        position = [-300][0];
        
    }

    
    // Make a function that updates the position after moving a specific direction
    void MovePlayer(int ROWS, int cposition[4][2], bool ifwall, string keypressed)
    {
        if (ifwall == false)
        {
            if (sf::Keyboard::isKeyPressed(sf::Key::Right))
                if (COLS >=0 && COLS <300)
                    COLS++; // If moving right, need to increase the x-axis position.
            
            if (sf::Keyboard::isKeyPressed(sf::Key::Left))
                if (COLS >0 && COLS <=300)
                    COLS--; // If the player is moving left, descrease the x axis position.
            
            if (sf::Keyboard::isKeyPressed(sf::Key::Up))
                if (ROWS >0 && ROWS <=300 )
                ROWS++; // If the player is moving up, increase the y axis position.
            
            if (sf::Keyboard::isKeyPressed(sf::Key::Down))
                if (ROWS >= 0 && ROWS <300) // Make sure that the position before the change is a valid area
                    ROWS--; // If the player is moving down, decrease the y axis position.
                
            }
        
    }
    
      
};


/******

 
 void MoveRight(int ROWS, int cposition[4][2], bool ifwall)
 {
 if (ifwall == false)
 ROWS++; // If moving right, need to increase the x-axis position.
 
 
 }
 void MoveLeft(int cposition[4][2], int ROWS, bool ifwall)
 {
 if (ifwall == false)
 
 ROWS--; // If moving right, need to increase the x-axis position.
 
 
 }
 void MoveUp(int cposition[4][2], int ROWS, bool ifwall)
 {
 if (ifwall == false)
 
 COLS--; // If moving right, need to increase the x-axis position.
 
 
 }
 void MoveDown(int cposition[4][2], int ROWS, bool ifwall)
 {
 if (ifwall == false)
 
 COLS--; // If moving right, need to increase the x-axis position.
 }




********/
