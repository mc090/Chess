#include "Square.h"

void Square::initializeSprite()
{
	_sprite.setSize(sf::Vector2f(100.f, 100.f));
	_sprite.setPosition((_position.getColumn() - 'A') * 100.f, ('8' - _position.getRow()) * 100.f);
}



Square::Square(const Position& position) :_position(position), _circle(nullptr),
_is_move_possible(false), _is_selected(false), _is_en_passant_possible(false), _is_occupied(false)
{
	initializeSprite();
}

void Square::setDefaultColor()
{
	reset();
}

void Square::reset()
{
	_is_move_possible = false;
	_is_en_passant_possible = false;
	_is_selected = false;
	delete _circle;
	_circle = nullptr;
}

void Square::markAsAvaliableMove()
{
	_is_move_possible = true;
	_circle = new MoveMarker(_position.getColumn() - 'A', '8' - _position.getRow(),
		_is_occupied ? 50.f : 20.f);
}

void Square::setSelectedColor()
{
	_sprite.setFillColor(sf::Color(78, 199, 161));
}

void Square::setCheckColor()
{
	_sprite.setFillColor(sf::Color::Red);
}

void Square::setIsOccupied(const bool is_occupied)
{
	_is_occupied = is_occupied;
}

void Square::setIsSelected(const bool is_selected)
{
	_is_selected = is_selected;
	setSelectedColor();
}

void Square::setIsEnPassantPossible(const bool is_en_passant_possible)
{
	_is_en_passant_possible = is_en_passant_possible;
}

bool Square::getIsOccupied() const
{
	return _is_occupied;
}

bool Square::getIsSelected() const
{
	return _is_selected;
}

bool Square::getIsMovePossible() const
{
	return _is_move_possible;
}

bool Square::getIsEnPassantPossible() const
{
	return _is_en_passant_possible;
}

void Square::draw(sf::RenderWindow* window)
{
	window->draw(_sprite);
	if (_circle)
	{
		_circle->draw(window);
	}
}
