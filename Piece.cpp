#include "Piece.h"


std::string Piece::getPosition()
{
	return _position;
}

void Piece::setPosition(const std::string& position)
{
	_sprite.setPosition((position[0] - 'A') * 100.f, abs(position[1] - '8') * 100.f );
}

void Piece::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}