#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
class MainScreen
{
private:
	sf::Font defaultFont;
	void fontConfig();
     sf::Texture texture;
     sf::Sprite background;
	sf::Text introText;
	sf::Text continueDecisionText;
	sf::Text closeDecisionText;
	void textConfig(sf::Text *, int, int, std::string);
	sf::RenderWindow window;
	bool decision;
public:
	MainScreen::MainScreen();
	bool getDecision();

	~MainScreen();
};

