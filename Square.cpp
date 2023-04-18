#include "Square.h"

void Square::initializeSprite()
{
	_sprite.setSize(sf::Vector2f(100.f, 100.f));
	_sprite.setPosition((_position[0] - 'A') * 100.f, ('8' - _position[1]) * 100.f);
}


void Square::draw(sf::RenderWindow* window) const
{
    window->draw(_sprite);
}
