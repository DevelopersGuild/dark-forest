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
        Block(Texture* texture, float x, float y, int wid, bool passable); //custom constructor
        
        /* ACSESSOR METHODS
        * these are used to find the values of a particular block
        */
        Sprite sprite(){ return *_sprite; }
        int xPos(){ return _xPos; }
        int yPos(){ return _yPos; }
        bool passable(){ return _passable; }
        // END ACCESSOR METHODS
        
    private:
    /*
        Block block(sf::Color::Red, 0,0,25, false);
    sf::Texture texture;
    texture.loadFromFile(resourcePath()+"assets/image.jpg");
    sf::Sprite sprite(texture);
    */
    
        Texture* _texture; // the texture of the sprite
        
        Sprite* _sprite; // the sprite itself
        
        bool _passable; // true if a character is able to walk on it
        int _xPos; // the x position of the block within the grid
        int _yPos; // the y pos of the block within the grid
        int _width; // the pixle width and height of the block
    
};
#endif /* Block_hpp */
