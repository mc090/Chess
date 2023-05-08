#include "Square.h"

void Square::initializeSprite()
{
	_sprite.setSize(sf::Vector2f(100.f, 100.f));
	_sprite.setPosition((_position.getColumn() - 'A') * 100.f, ('8' - _position.getRow()) * 100.f);
}



Square::Square(const Position& position) :_position(position), _circle(nullptr),
_is_selected(false), _is_en_passant_possible(false), _is_occupied(false)
{
	initializeSprite();
}

void Square::setDefaultColor()
{
	reset();
}

void Square::reset()
{
	_is_selected = false;
	_is_en_passant_possible = false;
	delete _circle;
	_circle = nullptr;
}

void Square::setPositionColor()
{
	_is_en_passant_possible = true;
}

void Square::setAvaliableMoveColor()
{
	_is_selected = true;
	_circle = new MoveMarker(_position.getColumn() - 'A', '8' - _position.getRow(),
		_is_occupied ? 50.f : 20.f);
}

void Square::setCheckColor()
{
	_sprite.setFillColor(sf::Color::Red);
}

void Square::setIsOccupied(const bool is_occupied)
{
	_is_occupied = is_occupied;
}

bool Square::getIsOccupied() const
{
	return _is_occupied;
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
	if (_circle)
	{
		_circle->draw(window);
	}
}
