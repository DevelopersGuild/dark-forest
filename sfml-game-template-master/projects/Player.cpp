#include "Player.h"

MainPlayer::MainPlayer()
{
     //position = [-300][0];
     texture.loadFromFile(resourcePath() + "assets/tempChar.png");
     mainCh.setTexture(texture);
     mainCh.setPosition(0,608);
}

void MainPlayer::MovePlayer(int ROWS, bool ifwall)
{
     if (ifwall == false)
     {
          //we cannot change ythe value of ROW and COL because they are constant!
          //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          //     if (COLS >= 0 && COLS <300)
          //          COLS++; // If moving right, need to increase the x-axis position.

          //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          //     if (COLS >0 && COLS <= 300)
          //          COLS--; // If the player is moving left, descrease the x axis position.

          //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          //     if (ROWS >0 && ROWS <= 300)
          //          ROWS++; // If the player is moving up, increase the y axis position.

          //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          //     if (ROWS >= 0 && ROWS <300) // Make sure that the position before the change is a valid area
          //          ROWS--; // If the player is moving down, decrease the y axis position.

     }

}
