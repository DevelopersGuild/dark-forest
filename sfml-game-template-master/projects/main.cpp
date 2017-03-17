#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include <iostream>
#include <string>
#include "IntroDialogue.h"
#include "map.h"
#include "Block.h"
#include "Player.h"
enum typeName { MAIN, HOW_TO, INTRO_DIALOGUE, PLAY, VICTORY, GAME_OVER, CREDIT } gameState;
const int B_ROW = 25;
const int B_COL = 20;
const int B_SIZE = 32;

void eventFun(sf::RenderWindow &window, sf::Event &event);
void Dialogue1(sf::RenderWindow &window, sf::Event &event, IntroDialogue &introDia, typeName &gameState);
void PlayMode(sf::RenderWindow &window, sf::Event &event, Map map, MainPlayer mainplayer, std::vector<std::vector<Block*>> block);
void endMode(sf::RenderWindow& window, sf::Event &event, typeName &gameState, std::string string, sf::Font font);
void CreditMode(sf::RenderWindow& window, sf::Event &event, typeName &gameState, sf::Font font);

int main()
{

     sf::RenderWindow window(sf::VideoMode((B_ROW * B_SIZE), (B_COL * B_SIZE)), "SFML Works!");
     //window.setVerticalSyncEnabled(true); // On WinPC this is good speed but too fast on Mac OS
     window.setFramerateLimit(30); 
     IntroDialogue introDia;
     Map map(B_COL, B_ROW, B_SIZE);
     map.checker();
     std::vector<std::vector<Block*>> block = map.layout();
     MainPlayer mainplayer;

     sf::Font font;
     font.loadFromFile(resourcePath() + "assets/BASKVILL.TTF");

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
          case VICTORY:
               endMode(window, event, gameState, "VICTORY!", font);
               break;
          case GAME_OVER: 
               endMode(window, event, gameState, "GAME OVER!", font);
               break;
          case CREDIT: 
               CreditMode(window, event, gameState, font);
               break;
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

void PlayMode(sf::RenderWindow &window, sf::Event &event, Map map, MainPlayer mainplayer, std::vector<std::vector<Block*>> block)
{
     while (gameState == PLAY)
     {
          eventFun(window, event);
          window.clear();
          mainplayer.MovePlayer(block);
          mainplayer.checkGoal(block);

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
          if (mainplayer.isGoal())
               gameState = VICTORY;

          mainplayer.draw(window);
          window.display();
     }
}

void endMode(sf::RenderWindow& window, sf::Event &event, typeName &gameState, std::string string, sf::Font font)
{
     sf::String sentence;
     sf::Text prompt(sentence, font, 77);
     prompt.setString(string);
     prompt.setColor(sf::Color(250, 218, 94)); //royal yellow
     prompt.setOrigin(prompt.getGlobalBounds().width / 2, prompt.getGlobalBounds().height / 2);
     prompt.setPosition(window.getSize().x / 2, 100);

     sf::Text retryMessage("press P to play again", font, 50);
     retryMessage.setOrigin(retryMessage.getGlobalBounds().width / 2, retryMessage.getGlobalBounds().height / 2);
     retryMessage.setPosition(window.getSize().x / 2, 250);
     retryMessage.setColor(sf::Color(250, 218, 94)); //royal yellow

     sf::Text creditMessage("press C to view credit", font, 50);
     creditMessage.setOrigin(creditMessage.getGlobalBounds().width / 2, creditMessage.getGlobalBounds().height / 2);
     creditMessage.setPosition(window.getSize().x / 2, 350);
     creditMessage.setColor(sf::Color(250, 218, 94));

     sf::Texture backgroundTexture;
     backgroundTexture.loadFromFile(resourcePath() + "assets/sky.jpg");
     sf::Sprite backgroundSprite(backgroundTexture);
     backgroundSprite.setScale(1.6, 2.0);

     while (gameState == GAME_OVER || gameState == VICTORY)
     {
          eventFun(window, event);
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
          {
               gameState = PLAY;
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
          {
               gameState = CREDIT;
          }
          window.clear();
          window.draw(backgroundSprite);
          window.draw(prompt);
          window.draw(retryMessage);
          window.draw(creditMessage);
          window.display();
     }
}

void CreditMode(sf::RenderWindow& window, sf::Event &event, typeName &gameState, sf::Font font)
{


     sf::Text title("Dark Forest", font, 99);
     title.setPosition(180, 50);
     title.setColor(sf::Color(250, 218, 94));

     sf::Text prompt("Developers: ", font, 32);
     prompt.setPosition(120, 180);
     prompt.setColor(sf::Color(250, 218, 94));

     sf::Text names("Ye-Eun Myung            Maggie Patrick\n"
                    "Deepti Raghuvaran      Rathna Kashyap\n"
                    "Shreyas Ketkar            Roshini Malempati\n", font, 32);
     names.setPosition(120, 240);
     names.setColor(sf::Color(250, 218, 94));


     sf::Text retryMessage("press P to play again", font, 50);
     retryMessage.setOrigin(retryMessage.getGlobalBounds().width / 2, retryMessage.getGlobalBounds().height / 2);
     retryMessage.setPosition(window.getSize().x / 2, 400);
     retryMessage.setColor(sf::Color(250, 218, 94)); //royal yellow

     sf::Texture backgroundTexture;
     backgroundTexture.loadFromFile(resourcePath() + "assets/sky.jpg");
     sf::Sprite backgroundSprite(backgroundTexture);
     backgroundSprite.setScale(1.6, 2.0);

     while (gameState == CREDIT)
     {
          eventFun(window, event);
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
          {
               gameState = PLAY;
          }
          window.clear();
          window.draw(backgroundSprite);
          window.draw(title);
          window.draw(prompt);
          window.draw(names);
          window.draw(retryMessage);
          window.display();
     }
}
