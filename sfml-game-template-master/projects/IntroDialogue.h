
#ifndef IntroDialogue_hpp
#define IntroDialogue_hpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "ResourcePath.h"

class IntroDialogue
{
private:
     std::ifstream txt;
     

public:
     void openfolder(std::ifstream &txt);
};
#endif