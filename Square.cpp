#include "Square.h"

void Square::initializeSprite()
{
	_sprite.setSize(sf::Vector2f(100.f, 100.f));
	_sprite.setPosition((_position[0] - 'A') * 100.f, ('8' - _position[1]) * 100.f);
}



Square::Square(std::string position) :_position(std::move(position)), _is_selected(false)
{
	initializeSprite();
}

void Square::setDefaultColor()
{
	_is_selected = false;
}

void Square::setPotenitalMoveColor()
{
	_is_selected = true;
}

bool Square::getIsSelected() const
{
	return _is_selected;
}

void Square::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}
