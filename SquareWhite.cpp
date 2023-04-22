#include "SquareWhite.h"

SquareWhite::SquareWhite(const std::string& position) :Square(position)
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

void SquareWhite::setPotenitalMoveColor()
{
	Square::setPotenitalMoveColor();
	_sprite.setFillColor(sf::Color(255, 0, 255));
}
