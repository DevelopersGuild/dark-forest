#include <SFML/Graphics.hpp>
#include "ResourcePath.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML Works!");
    window.setVerticalSyncEnabled(true);
    // create a wall in the shape of rectangle
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(20.f, 10.f));
    rect.setFillColor(sf::Color::White);
    rect.setPosition(20.0, 30.0);
    
    // create the main player in the shape of a circle for now
    sf::CircleShape player(20.f);
    player.setFillColor(sf::Color::Green);
    player.setOrigin(-150.f, -150.f);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // Update the position, and check whether that value is equal to the bool value returned by the walls coordinates. If it's true, call the function that updates the position
            
            player.move(0, -2.00);
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player.move(0.0, 2.00);
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.move(-2.00, 0.0);
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            
            player.move(2.00, 0.0);
        }
        
        
        window.clear();
        window.draw(rect);
        window.draw(player);
        window.display();
    }
    
    return 0;
}
