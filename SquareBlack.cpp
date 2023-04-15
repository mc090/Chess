#include "SquareBlack.h"

SquareBlack::SquareBlack(int x, int y) :Square(x, y)
{
	Default();
}

void SquareBlack::Default()
{
	sprite.setFillColor(sf::Color(119, 110, 122));
}

void SquareBlack::Position()
{
	sprite.setFillColor(sf::Color(187, 201, 64));
}

void SquareBlack::Move()
{
	sprite.setFillColor(sf::Color(104, 78, 57));
}