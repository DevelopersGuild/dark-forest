#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include <iostream>

#include "map.h"
#include "Block.h"
int main()
{
    
	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML Works!");
    Map map(20, 32, 25);
    map.checker();
    
    Block block(sf::Color::Red, 0,0,25, false);
    
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
                window.draw(map.layout()[i][j]->image());
            }
        }
		window.display();
	}

	return 0;
}
