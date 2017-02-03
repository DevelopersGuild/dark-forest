#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include "Overlap.h"
#include <iostream>

#include "map.h"
#include "Block.h"
#include "IntroDialogue.h"

int main()
{
    
	sf::RenderWindow window(sf::VideoMode(800, 640), "SFML Works!");
    Map map(20, 25, 32);
    map.checker();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
        for (int i = map.row() - 1; i >= 0; --i){
            for (int j = map.col() - 1; j >= 0; --j){
                window.draw(map.layout()[i][j]->sprite());
            }
        }
		window.display();
	}

	return 0;
}
