//
//  IntroDialogue.hspp
//  SampleGame
//
//  Created by Ye Eun Myung on 2/10/2017
//  Copyright © 2017 De Anza College Developers' Guild. All rights reserved.
//
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
     void getDialogue(std::string fileName) {
          txt.open(resourcePath() + fileName);
     }
     void readDialogue(sf::RenderWindow &window); //opens the folder and starts reading 
     void printDialogue(sf::RenderWindow &window); //draws the text
     bool finishDia = false; //flag for end of the dialogue

};
#endif