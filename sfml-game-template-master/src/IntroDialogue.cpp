#include "IntroDialogue.h"

IntroDialogue::IntroDialogue()
{
     txt.open(resourcePath() + "assets/startDia.txt");

}
void IntroDialogue::openfolder(std::ifstream &txt)
{
     if (!txt.is_open())
     {
          std::cout << "Cannot open the startDia.txt!!\n";
     }

     while (txt.eof())
     {
          
     }

}