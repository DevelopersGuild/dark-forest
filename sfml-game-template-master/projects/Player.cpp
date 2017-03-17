//
//  Player.cpp
//  SampleGame
//
//  Created by Deepti 1/27/2017
//  Edited by Ye Eun Myung on 03/03/2017
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//
#include "Player.h"

MainPlayer::MainPlayer()
{
     texture.loadFromFile(resourcePath() + "assets/MainCh.png");
     mainCh.setTexture(texture);
     mainCh.setPosition(0,608);
     live = true;
     goal = false;
}

void MainPlayer::MovePlayer(std::vector<std::vector<Block*>> block)
{
     sf::Vector2f currPos = mainCh.getPosition();
     move = false;
     for (int i = 0; i < block.size(); i++)
     {
          for (int j = 0; j < block[i].size(); j++)
          {
               if ((currPos.x == block[i][j]->xPos()) && (currPos.y == block[i][j]->yPos()))
               {
                    
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                         if ((j + 1) > (block[i].size()-1))
                         {
                              //if main character is going out of the window
                              mainCh.setPosition(currPos);
                              break;
                         }
                         if (block[i][j + 1]->passable())
                         {
                              mainCh.setPosition(block[i][j + 1]->xPos(), block[i][j + 1]->yPos());
                              move = true;
                         }
                         else
                              mainCh.setPosition(currPos);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                         //if main character is going out of the window
                         if ((j - 1) < 0)
                         {
                              mainCh.setPosition(currPos);
                              break;
                         }
                         if (block[i][j - 1]->passable())
                         {
                              mainCh.setPosition(block[i][j - 1]->xPos(), block[i][j - 1]->yPos());
                              move = true;
                         }
                         else
                              mainCh.setPosition(currPos);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                         //if main character is going out of the window
                         if ((i - 1) < 0)
                         {
                              mainCh.setPosition(currPos);
                              break;
                         }
                         //go up a row
                         if (block[i - 1][j]->passable())
                         {
                              mainCh.setPosition(block[i - 1][j]->xPos(), block[i - 1][j]->yPos());
                              move = true;
                         }
                         else
                              mainCh.setPosition(currPos);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                         //if main character is going out of the window
                         if ((i + 1) > (block.size()-1))
                         {
                              mainCh.setPosition(currPos);
                              break;
                         }
                         if (block[i + 1][j]->passable())
                         {
                              mainCh.setPosition(block[i + 1][j]->xPos(), block[i + 1][j]->yPos());
                              move = true;
                         }
                         else
                              mainCh.setPosition(currPos);
                    }
                    break;
               }
          }//end for
     }//end for
}

void MainPlayer::checkGoal(std::vector<std::vector<Block*>> block)
{
     int last = block[0].size() - 1;
     
     if (mainCh.getPosition().x == block[0][last]->xPos() && mainCh.getPosition().y == block[0][last]->yPos())
     {
          goal = true;
     }
}

