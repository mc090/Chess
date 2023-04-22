#include "SquareBlack.h"

SquareBlack::SquareBlack(const std::string& position) :Square(position)
{
	setDefaultColor();
}

void SquareBlack::setDefaultColor()
{
	Square::setDefaultColor();
	_sprite.setFillColor(sf::Color(119, 110, 122));
}

void SquareBlack::setPositionColor()
{
	_sprite.setFillColor(sf::Color(187, 201, 64));
}

void SquareBlack::setPotenitalMoveColor()
{
	Square::setPotenitalMoveColor();
	_sprite.setFillColor(sf::Color(128, 0, 128));
}