//
//  Block.hpp
//  SampleGame
//
//  Created by Margaret Patrick on 1/26/17.
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//

/*
*
*/

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <string>

#include <SFML/Graphics.hpp>
#include "ResourcePath.h"

using namespace sf;
class Block{
    public:
    /* INIT
    * sets all values passed, creates the "image" of the block
    * eventually the goal will be to add unique features to certain blocks, perhaps subclassing this
    */
        Block(); //default constructor
        Block(Color color, float x, float y, int wid, bool passable); //custom constructor
        
        /* ACSESSOR METHODS
        * these are used to find the values of a particular block
        */
        RectangleShape image(){ return _image; }
        Color color(){ return _color; }
        int xPos(){ return _xPos; }
        int yPos(){ return _yPos; }
        bool passable(){ return _passable; }
        // END ACCESSOR METHODS
        
    private:
        RectangleShape _image; // the shape itself
        
        bool _passable; // true if a character is able to walk on it
        Color _color; // the color of the shape, eventually will be replaced with 'texture' once we have sprites
        int _xPos; // the x position of the block within the grid
        int _yPos; // the y pos of the block within the grid
        int _width; // the pixle width and height of the block
    
};
#endif /* Block_hpp */
