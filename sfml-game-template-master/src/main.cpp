#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include <iostream>

#include "map.hpp"
#include "Block.hpp"
int main()
{
    
	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML Works!");
    Map map;
    map.checker();
    
    Block block(sf::Color::Red, 0,0,25);
    
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
        
		window.clear();
        
        for (int i = map.layout().ROW - 1; i >= 0; --i){
            for (int j = map.layout().COL - 1; j >= 0; --j){
                window.draw(map.layout().grid[i][j]->image());
            }
        }
		window.display();
	}

	return 0;
}
