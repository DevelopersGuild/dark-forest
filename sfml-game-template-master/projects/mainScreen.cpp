#include "mainScreen.h"


MainScreen::MainScreen()
{
	window.create(sf::VideoMode(800, 500), "Intro Window");
	fontConfig();


	textConfig(&introText, 80, 130, "Welcome");
	textConfig(&continueDecisionText, 40, 250, "'Enter' to Continue");
	textConfig(&closeDecisionText, 40, 300, "Close(x) to Exit");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				decision = false;
				window.close();
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == 13)
				{
					decision = true;
					window.close();
				}
			}
		}

		window.clear();

		window.draw(introText);
		window.draw(continueDecisionText);
		window.draw(closeDecisionText);

		window.display();

	}
}

void MainScreen::fontConfig()
{
	if (!(defaultFont.loadFromFile(resourcePath() + "assets/LiberationSans-Regular.ttf")))
		std::cout << "could not load font";
}

void MainScreen::textConfig(sf::Text *text, int size, int yD, std::string string)
{
	text->setFont(defaultFont);
	text->setString(string);
	text->setCharacterSize(size);
	text->setColor(sf::Color::White);
	text->setStyle(sf::Text::Regular);
	text->setOrigin
	(text->getLocalBounds().left + text->getLocalBounds().width / 2,
		text->getLocalBounds().top + text->getLocalBounds().height / 2);
	text->setPosition(sf::Vector2f(400, yD));
}

bool MainScreen::getDecision()
{
	return decision;
}

MainScreen::~MainScreen()
{
}
