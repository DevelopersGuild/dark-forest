#include "Monster.h"

Monster::Monster()
{
     texture.loadFromFile(resourcePath()+"assets/Minotaur.png");
     monster.setTexture(texture);
}

void Monster::setInitPosition(std::vector<std::vector<Block*>> block)
{
     srand((unsigned int)time(0));
     int xPos = rand() % (19);
     int yPos = rand() % (24);
     while (!block[xPos][yPos]->passable())
     {
          xPos = rand() % (19);
          yPos = rand() % (24);
     }
     sf::Vector2f position(block[xPos][yPos]->xPos(), block[xPos][yPos]->yPos());
     monster.setPosition(position); //RANDOM inside the map tile

}
void Monster::checkBoundaries(std::vector<std::vector<Block*>> block, sf::Vector2f mainChPos, bool isMainChMove)
{
     sf::Vector2f currPos = monster.getPosition();
     int i = 0;
     srand((unsigned int)time(0));
     int number = (rand() %4)+1;
     isMove = false;
     if (isMainChMove)
     {
          for (int i = 0; i < block.size(); i++)
          {
               for (int j = 0; j < block[i].size(); j++)
               {
                    if (block[i][j]->xPos() == currPos.x && block[i][j]->yPos() == currPos.y)
                    {
                         //if the monster went out of the right side
                         if ((j + 1) > (block[i].size() - 1))
                         {
                              monster.setPosition(currPos);

                              ////try up and down and left
                              //if ((i - 1) >= 0 && (i + 1) < (block.size()))
                              //{
                              //     while (!isMove)
                              //     {
                              //          while (number == 1)
                              //          {
                              //               number = (rand() % 4) + 1;
                              //          }
                              //          moveOrder(block, number, i, j);
                              //     }
                              //}
                              //break;
                         }
                         //if the monster went out of the left side
                         if ((j - 1) < 0)
                         {
                              monster.setPosition(currPos);
                              //try up and down and right
                              //if ((i - 1) >= 0 && (i + 1) < (block.size()))
                              //{
                              //     while (!isMove)
                              //     {
                              //          while (number == 2)
                              //          {
                              //               number = (rand() % 4) + 1;
                              //          }
                              //          moveOrder(block, number, i, j);
                              //     }
                              //}
                              //break;
                         }
                         //if the monster went out of the bottom
                         if ((i + 1) > (block.size() - 1))
                         {
                              monster.setPosition(currPos);
                              //if ((j - 1) >= 0 && (j + 1) < (block[i].size()))
                              //{
                              //     while (!isMove)
                              //     {
                              //          while (number == 3)
                              //          {
                              //               number = (rand() % 4) + 1;
                              //          }
                              //          moveOrder(block, number, i, j);
                              //     }
                              //}
                              //break;
                         }
                         //if the monster went out of the top
                         if ((i - 1) < 0)
                         {
                              monster.setPosition(currPos);  
                              //if ((j - 1) >= 0 && (j + 1) < (block[i].size()))
                              //{
                              //     while (!isMove)
                              //     {
                              //          while (number == 4)
                              //          {
                              //               number = (rand() % 4) + 1;
                              //          }
                              //          moveOrder(block, number, i, j);
                              //     }
                              //}
                              //break;
                         }

                         //four corners
                         if ((j + 1) > (block[i].size() - 1) && (i - 1) < 0)
                         {
                              monster.setPosition(currPos);

                              ////move left or down
                              //std::cout << number << "!!\n";

                              //while (!isMove)
                              //{

                              //     while (number != 2 || number != 3)
                              //     {
                              //          number = (rand() % 4) + 1;
                              //     }
                              //     moveOrder(block, number, i, j);
                              //}
                         }
                         if ((j - 1) < 0 && (i + 1) > (block.size() - 1))
                         {
                              monster.setPosition(currPos);

                              //std::cout << number << "!!\n";

                              ////move right or up
                              //while (number != 1 || number != 4)
                              //{
                              //     number = (rand() % 4) + 1;

                              //}
                              //while (!isMove)
                              //{

                              //     moveOrder(block, number, i, j);
                              //}
                         }
                         if ((j - 1) < 0 && (i - 1) < 0)
                         {
                              monster.setPosition(currPos);

                              //std::cout << number << "!!\n";

                              ////move right or down
                              //while (number != 1 || number != 3)
                              //{
                              //     number = (rand() % 4) + 1;

                              //}
                              //while (!isMove)
                              //{

                              //     moveOrder(block, number, i, j);
                              //}
                         }
                         if ((j + 1) > (block[i].size() - 1) && (i + 1) > (block.size() - 1))
                         {
                              monster.setPosition(currPos);
                              ////move left or up
                              //std::cout << number << "!!\n";
                              //while (number != 2 || number != 4)
                              //{
                              //     number = (rand() % 4) + 1;                                   

                              //}
                              //while (!isMove)
                              //{

                              //     moveOrder(block, number, i, j);
                              //}
                         }
                         
                         //while (!isMove)
                         //{
                         //     number = (rand() % 4) + 1;

                         //     moveOrder(block, number, i, j);
                         //}
                         //break;
                    }
               }
          }
     }
}

void Monster::findPath(std::vector<std::vector<Block*>> block, sf::Vector2f mainChPos, bool isMainChMove)
{
     //automatically find the path to the currednt player position
     int rowPos;
     int colPos;
     //get the row and col of where the main character is at
     for (int i = 0; i < block.size(); i++)
     {
          for (int j = 0; j < block[i].size(); j++)
          {
               if (block[i][j]->xPos() == mainChPos.x && block[i][j]->yPos() == mainChPos.y)
               {
                    rowPos = i;
                    colPos = j;
                    break;
               }
          }
     }
     isMove = false;

     sf::Vector2f currPos = monster.getPosition();
     //find the path to the main character
     if (isMainChMove && !isMove)
     {
          for (int i = 0; i < block.size(); i++)
          {
               for (int j = 0; j < block[i].size(); j++)
               {
                    //find the current block position of monster
                    if (block[i][j]->xPos() == monster.getPosition().x && block[i][j]->yPos() == monster.getPosition().y)
                    {
                         //if monster is above the mainCharacter
                         if (rowPos > i)
                         {
                              if ((i + 1) < block.size())
                              {
                                   moveOrder(block, 3, i, j); //down
                                   if (isMove) goto endNestedFor;
                              }

                              if (colPos < j)
                              {
                                   if ((j - 1) >= 0)
                                   {
                                        moveOrder(block, 2, i, j);
                                        if (isMove) goto endNestedFor;
                                   }
                              }
                              if (colPos > j)
                              {
                                   if ((j + 1) < block[i].size())
                                   {
                                        moveOrder(block, 1, i, j); //right
                                        if (isMove)goto endNestedFor;
                                   }
                              }
                              if ((i - 1) >= 0)
                              {
                                   moveOrder(block, 4, i, j); //up
                                   if (isMove) goto endNestedFor;
                              }
                         }
                         //if monster is below a row
                         if (rowPos < i)
                         {
                              if ((i - 1) >= 0)
                              {
                                   moveOrder(block, 4, i, j); // up
                                   if (isMove) goto endNestedFor;
                              }
                              if (colPos < j)
                              {
                                   if ((j - 1) >= 0)
                                   {
                                        moveOrder(block, 2, i, j); //left
                                        if (isMove) goto endNestedFor;
                                   }
                              }
                              if (colPos > j)
                              {
                                   if ((j + 1) < block[i].size())
                                   {
                                        moveOrder(block, 1, i, j); //right
                                        if (isMove) goto endNestedFor;
                                   }
                              }
                              if ((i + 1) < block.size())
                              {
                                   moveOrder(block, 3, i, j); //down
                                   if (isMove) goto endNestedFor;
                              }
                         }
                         //if the monster is on the right side the main character
                         if (colPos < j)
                         {
                              if ((j - 1) >= 0) //positive number
                              {
                                   moveOrder(block, 2, i, j); //move left first
                                   if (isMove) goto endNestedFor;
                              }

                              if (rowPos > i) //if the monster is above the mainCh
                              {
                                   if ((i + 1) < block.size())
                                   {
                                        moveOrder(block, 3, i, j); //down
                                        if (isMove) goto endNestedFor;
                                   }
                              }
                              if (rowPos < i) //if the mosnter is below the mainCh
                              {
                                   if ((i - 1) >= 0)
                                   {
                                        moveOrder(block, 4, i, j); //up
                                        if (isMove) goto endNestedFor;
                                   }
                              }
                              if ((j + 1) < block[i].size())
                              {
                                   moveOrder(block, 1, i, j); //right
                                   if (isMove) goto endNestedFor;
                              }

                         }
                         //if the monster is on the left side the main character
                         if (colPos > j)
                         {
                              if ((j + 1) < block[i].size())
                              {
                                   moveOrder(block, 1, i, j); //right
                                   if (isMove) goto endNestedFor;
                              }
                              if (rowPos > i) //if the monster is above the mainCh
                              {
                                   if ((i + 1) < block.size())
                                   {
                                        moveOrder(block, 3, i, j); //down
                                        if (isMove) goto endNestedFor;
                                   }
                              }
                              if (rowPos < i) //if the mosnter is below the mainCh
                              {
                                   if ((i - 1) >= 0)
                                   {
                                        moveOrder(block, 4, i, j); //up
                                        if (isMove) goto endNestedFor;
                                   }
                              }
                              if ((j - 1) >= 0)
                              {
                                   moveOrder(block, 2, i, j); //move left
                                   if (isMove) goto endNestedFor;
                              }

                         }
                         goto endNestedFor;
                    }//end if (block[i][j]->xPos() == monster.getPosition().x && block[i][j]->yPos() == monster.getPosition().y)
               }
          }
     endNestedFor:;
     }
}

void Monster::moveOrder(std::vector<std::vector<Block*>> block, int num, int i, int j)
{
     
     switch (num)
     {
     case 1:
          if (block[i][j + 1]->passable()){
               monster.setPosition(block[i][j+1]->xyPos()); //move right
               isMove = true;
          }
          break;
     case 2:
          if (block[i][j - 1]->passable()){
               monster.setPosition(block[i][j - 1]->xyPos()); //move left
               isMove = true;
          }
          break;
     case 3:
          if (block[i + 1][j]->passable()){
               monster.setPosition(block[i + 1][j]->xyPos()); //move down
               isMove = true;
          }
          break;
     case 4:
          if (block[i - 1][j]->passable()){
               monster.setPosition(block[i - 1][j]->xyPos()); //move up
               isMove = true;
          }

          break;
     }
}