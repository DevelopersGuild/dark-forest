
#ifndef IntroDialogue_hpp
#define IntroDialogue_hpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "ResourcePath.h"

class IntroDialogue
{
private:
     sf::Texture texture;
     sf::Sprite campfireS;
     std::ifstream txt; //gets the file
     std::string dialogue1 = ""; //gets the line from the inputfile
     sf::Font font; //font for the text
     sf::Text text1; //to fraw current text
     sf::Text text2; //to draw previous text

     //flags to display dialogues one at a time
     bool wasPressed = false;
     bool isPressed = false;

public:
     IntroDialogue(); //constructor 
     void readDialogue(sf::RenderWindow &window); //opens the folder and starts reading 
     void printDialogue(sf::RenderWindow &window); //draws the text
     bool endDia = false; //flag for end of the dialogue

};
#endif