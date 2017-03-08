#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include <iostream>

#include "IntroDialogue.h"
#include "map.h"
#include "Block.h"
#include "Player.h"
enum typeName { MAIN, HOW_TO, INTRO_DIALOGUE, PLAY, GAME_OVER, CREDIT } gameState;

void eventFun(sf::RenderWindow &window, sf::Event &event);
void Dialogue1(sf::RenderWindow &window, sf::Event &event, IntroDialogue &introDia, typeName &gameState);
void PlayMode(sf::RenderWindow &window, sf::Event &event, Map map, MainPlayer mainplayer, vector<vector<Block*>> block);

int main()
{
    
     sf::RenderWindow window(sf::VideoMode(800, 640), "SFML Works!");
     window.setVerticalSyncEnabled(true);
     IntroDialogue introDia;
     Map map(20, 25, 32);
     map.checker();
     vector<vector<Block*>> block = map.layout();
     MainPlayer mainplayer;
     
     gameState = INTRO_DIALOGUE;

     while (window.isOpen())
     {
          window.clear();
          //all the move statements should be in the class not here! 
          sf::Event event;
          eventFun(window, event);
          switch (gameState)
          {
          //case MAIN: break;
          //case HOW_TO: break;
          case INTRO_DIALOGUE:
               Dialogue1(window, event, introDia, gameState);
               break;
          case PLAY:
               PlayMode(window, event, map, mainplayer, block);
               break;
          //case GAME_OVER: break;
          //case CREDIT: break;

          }

     }//end of while(window.isopen())

     return 0;
}

void eventFun(sf::RenderWindow &window, sf::Event &event)
{
     while (window.pollEvent(event))
     {
          if (event.type == sf::Event::Closed)
               window.close();
     }
}
void Dialogue1(sf::RenderWindow &window, sf::Event &event, IntroDialogue &introDia, typeName &gameState)
{
     while (gameState == INTRO_DIALOGUE)
     {
          eventFun(window, event);
          introDia.readDialogue(window);
          if (introDia.endDia)
          {
               gameState = PLAY;
          }
     }
}
void PlayMode(sf::RenderWindow &window, sf::Event &event, Map map, MainPlayer mainplayer, vector<vector<Block*>> block)
{
     while (gameState == PLAY)
     {
          eventFun(window, event);
          window.clear();
          mainplayer.MovePlayer(block);
          
          for (int i = map.row() - 1; i >= 0; --i)
          {
               for (int j = map.col() - 1; j >= 0; --j)
               {
                    window.draw(map.layout()[i][j]->sprite());
               }
          }
          std::cout << mainplayer.isMove() << std::endl;
          if(!mainplayer.isLive())
               gameState = GAME_OVER;

          mainplayer.draw(window);
          window.display();
     }
}
