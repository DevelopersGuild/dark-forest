#include "randomMonster.h"

RandomMonster::RandomMonster()
{
	texture.loadFromFile(resourcePath() + "assets/Minotaur.png");
	monster.setTexture(texture);
	monster.setPosition(0, 0);
}

void RandomMonster::playAgain()
{
	monster.setPosition(0, 0);
	reinitialise();
}

void RandomMonster::findPassable(std::vector<std::vector<Block*>> block)
{
	sf::Vector2f currPos = monster.getPosition();
	for (int i = 0; i < block.size(); i++) {
		for (int j = 0; j < block[i].size(); j++) {
			if ((currPos.x == block[i][j]->xPos()) && (currPos.y == block[i][j]->yPos())) {
				if ((j + 1) <= (block[i].size() - 1) && block[i][j + 1]->passable()) {	// right
					passable[0] = true;
					numPassable++;
					findPassableIndex[numPassable - 1] = 0;
					std::cout << "R";
				}
				if ((j - 1) >= 0 && block[i][j - 1]->passable()) {	// left
					passable[1] = true;
					numPassable++;
					findPassableIndex[numPassable - 1] = 1;
					std::cout << "L";
				}
				if ((i - 1) >= 0 && block[i - 1][j]->passable()) {	// up
					passable[2] = true;
					numPassable++;
					findPassableIndex[numPassable - 1] = 2;
					std::cout << "U";
				}
				if ((i + 1) <= (block.size() - 1) && block[i + 1][j]->passable()) {	// down
					passable[3] = true;
					numPassable++;
					findPassableIndex[numPassable - 1] = 3;
					std::cout << "D";
				}
				std::cout << std::endl;
			}
		}
	}
}

void RandomMonster::generateRandom()
{
	srand(time(NULL));
	if (numPassable != 0)
		selectedNum = (rand()) % numPassable;
	else
		return;
}

void RandomMonster::moveMonster(std::vector<std::vector<Block*>> block)
{
	findPassable(block);
	if (numPassable == 0)
		return;
	generateRandom();
	sf::Vector2f currPos = monster.getPosition();
//	move = false;

	for (int i = 0; i < block.size(); i++)
	{
		for (int j = 0; j < block[i].size(); j++)
		{
			if ((currPos.x == block[i][j]->xPos()) && (currPos.y == block[i][j]->yPos()))
			{

				if (findPassableIndex[selectedNum] == 0)	// right
				{
					if ((j + 1) >(block[i].size() - 1))
					{
						//if main character is going out of the window
						monster.setPosition(currPos);
						break;
					}
					if (block[i][j + 1]->passable())
					{
						monster.setPosition(block[i][j + 1]->xPos(), block[i][j + 1]->yPos());
					//	move = true;
					}
					else
						monster.setPosition(currPos);
				}
				if (findPassableIndex[selectedNum] == 1) // left
				{
					//if main character is going out of the window
					if ((j - 1) < 0)
					{
						monster.setPosition(currPos);
						break;
					}
					if (block[i][j - 1]->passable())
					{
						monster.setPosition(block[i][j - 1]->xPos(), block[i][j - 1]->yPos());
						//move = true;
					}
					else
						monster.setPosition(currPos);
				}
				if (findPassableIndex[selectedNum] == 2)	// up
				{
					//if main character is going out of the window
					if ((i - 1) < 0)
					{
						monster.setPosition(currPos);
						break;
					}
					//go up a row
					if (block[i - 1][j]->passable())
					{
						monster.setPosition(block[i - 1][j]->xPos(), block[i - 1][j]->yPos());
					//	move = true;
					}
					else
						monster.setPosition(currPos);
				}
				if (findPassableIndex[selectedNum] == 3)	// down
				{
					//if main character is going out of the window
					if ((i + 1) > (block.size() - 1))
					{
						monster.setPosition(currPos);
						break;
					}
					if (block[i + 1][j]->passable())
					{
						monster.setPosition(block[i + 1][j]->xPos(), block[i + 1][j]->yPos());
					//	move = true;
					}
					else
						monster.setPosition(currPos);
				}
				break;
			}
		}//end for
	}//end for
	reinitialise();
}

void RandomMonster::reinitialise()
{
	passable[0] = 0;
	passable[1] = 0;
	passable[2] = 0;
	passable[3] = 0;
	findPassableIndex[0] = 0;
	findPassableIndex[1] = 0;
	findPassableIndex[2] = 0;
	findPassableIndex[3] = 0;
	selectedNum = -1;
	numPassable = 0;
}

RandomMonster::~RandomMonster()
{
}
