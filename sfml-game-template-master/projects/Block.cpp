//
//  Block.cpp
//  SampleGame
//
//  Created by Margaret Patrick on 1/26/17.
//  Edited by Ye Eun Myung on 03/08/2017
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//

#include "Block.h"

/*default constructor
*sets all values to zero and color black
*/

Block::Block(){
            _xPos = 0;
            _yPos = 0;
            _xyPosition = sf::Vector2f(0, 0);
            _width = 0;
            
            
            /*
            _image.setSize(Vector2f(_width, _width));  
            _image.setPosition(_xPos, _yPos);
            _image.setFillColor(_color);
            */
}

/*custom constructor
*@param: color of the block
*@param: x position of the block
*@param: width of the block
*@param: bool, wither the block can be walked on
*/

Block::Block(sf::Texture* texture, float x, float y, int wid, bool passable) {
     _xPos = x;
     _yPos = y;
     _xyPosition = sf::Vector2f(x, y);
     _width = wid;
     _texture = texture;
     _passable = passable;
     _sprite = new sf::Sprite(*texture);

     _sprite->setPosition(x, y);
}

