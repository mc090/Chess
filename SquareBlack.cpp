#include "SquareBlack.h"

SquareBlack::SquareBlack(const Position& position) :Square(position)
{
	setDefaultColor();
}

void SquareBlack::setDefaultColor()
{
	Square::setDefaultColor();
	_sprite.setFillColor(sf::Color(119, 110, 122));
}

void SquareBlack::setLastMoveColor()
{
	_sprite.setFillColor(sf::Color(187, 201, 64));
}