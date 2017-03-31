#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Player.h"
#include "ResourcePath.h"
// #include "Walls.h"
#include "Block.h"
#include <string>
#include <iostream>
#include <vector>
class RandomMonster
{
private:
	sf::Texture texture;
	sf::Sprite monster;
	bool passable[4]; // right, left, up, down
	int findPassableIndex[4];
	int numPassable;
	int selectedNum;
	void findPassable(std::vector<std::vector<Block*>>);
	void generateRandom();
	void reinitialise();
	// bool move;
public:
	RandomMonster();
	void moveMonster(std::vector<std::vector<Block*>> block);
	// bool isMove() { return move; }
	void draw(sf::RenderWindow &window) { window.draw(monster); }
	void playAgain();
	sf::Vector2f getPos()  { return monster.getPosition(); };
	~RandomMonster();
};

