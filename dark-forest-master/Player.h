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
    // Make a function that updates the position after moving a specific direction
    
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
    
};
