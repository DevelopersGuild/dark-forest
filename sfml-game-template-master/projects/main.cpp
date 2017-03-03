#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include <iostream>

#include "IntroDialogue.h"
#include "map.h"
#include "Block.h"
#include "Player.h"
enum typeName { MAIN, HOW_TO, INTRO_DIALOGUE, PLAY, GAME_OVER, CREDIT } gameState;

void Dialogue1(sf::RenderWindow &window, IntroDialogue &introDia, typeName &gameState);
void PlayMode(sf::RenderWindow &window, Map map, MainPlayer mainplayer);

int main()
{
    
     sf::RenderWindow window(sf::VideoMode(800, 640), "SFML Works!");
     window.setVerticalSyncEnabled(true);
     IntroDialogue introDia;
     Map map(20, 25, 32);
     gameState = INTRO_DIALOGUE;
     MainPlayer mainplayer;
     while (window.isOpen())
     {
          window.clear();
          //all the move statements should be in the class not here! 
          sf::Event event;
          while (window.pollEvent(event))
          {
               if (event.type == sf::Event::Closed)
                    window.close();
          }

          switch (gameState)
          {
          //case MAIN: break;
          //case HOW_TO: break;
          case INTRO_DIALOGUE:
               Dialogue1(window, introDia, gameState);
               break;
          case PLAY:
               PlayMode(window, map, mainplayer);
               break;
          //case CREDIT: break;

          }

     }//end of while(window.isopen())

     return 0;
}


void Dialogue1(sf::RenderWindow &window, IntroDialogue &introDia, typeName &gameState)
{
      while (window.isOpen() && gameState == INTRO_DIALOGUE)
     {
          introDia.readDialogue(window);
          if (introDia.endDia)
          {
               gameState = PLAY;
          }
     }
}
void PlayMode(sf::RenderWindow &window, Map map, MainPlayer mainplayer)
{
     map.checker();
     //mainplayer.MovePlayer(//get the col, row and the boolean for the Block position);
    // while (window.isOpen() && gameState == PLAY)
    //{
          window.clear();
          for (int i = map.row() - 1; i >= 0; --i)
          {
               for (int j = map.col() - 1; j >= 0; --j)
               {
                    window.draw(map.layout()[i][j]->sprite());
               }
          }
          //if(gameover)
          //gameState = GAME_OVER;
    // }
          mainplayer.draw(window);
     window.display();
}
