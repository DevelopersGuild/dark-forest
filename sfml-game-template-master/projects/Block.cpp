//
//  Block.cpp
//  SampleGame
//
//  Created by Margaret Patrick on 1/26/17.
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//

#include "Block.hpp"
#include <SFML/Graphics.hpp>
#include "ResourcePath.h"

using namespace sf;
Block::Block(){
            _color = sf::Color::Black;
            _xPos = 0;
            _yPos = 0;
            _width = 0;
            
            _image.setSize(Vector2f(_width, _width));  
            _image.setPosition(_xPos, _yPos);
            _image.setFillColor(_color);
}

Block::Block(Color color, float x, float y, int wid, bool passable){
            _color = color;
            _xPos = x;
            _yPos = y;
            _width = wid;
            
            _image.setSize(Vector2f(wid, wid));  
            _image.setPosition(x, y);
            _image.setFillColor(color);
        }
