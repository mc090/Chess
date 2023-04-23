#include "Square.h"

void Square::initializeSprite()
{
	_sprite.setSize(sf::Vector2f(100.f, 100.f));
	_sprite.setPosition((_position.getColumn() - 'A') * 100.f, ('8' - _position.getRow()) * 100.f);
}



Square::Square(const Position& position) :_position(position),_is_selected(false), _is_en_passant_possible(false)
{
	initializeSprite();
}

void Square::setDefaultColor()
{
	_is_selected = false;
	_is_en_passant_possible = false;
}

void Square::setPositionColor()
{
	_is_en_passant_possible = true;
}

void Square::setAvaliableMoveColor()
{
	_is_selected = true;
}

bool Square::getIsSelected() const
{
	return _is_selected;
}

bool Square::getIsEnPassantPossible() const
{
	return _is_en_passant_possible;
}

void Square::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}
