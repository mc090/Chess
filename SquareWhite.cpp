#include "SquareWhite.h"

SquareWhite::SquareWhite(const Position& position) :Square(position)
{
	setDefaultColor();
}

void SquareWhite::setDefaultColor()
{
	Square::setDefaultColor();
	_sprite.setFillColor(sf::Color(255, 240, 205));
}

void SquareWhite::setPositionColor()
{
	_sprite.setFillColor(sf::Color(247, 246, 133));
}
