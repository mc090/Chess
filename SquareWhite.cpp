#include "SquareWhite.h"

SquareWhite::SquareWhite(int x, int y):Square(x,y)
{
	Default();
}

void SquareWhite::Default()
{
	sprite.setFillColor(sf::Color(255, 240, 205));
}

void SquareWhite::Position()
{
	sprite.setFillColor(sf::Color(247, 246, 133));
}

void SquareWhite::Move()
{
	sprite.setFillColor(sf::Color(163, 147, 123));
}
