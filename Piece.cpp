#include "Piece.h"


Piece::Piece(const team side, std::string position) :_side(side), _position(std::move(position))
{

}

std::string Piece::getPosition()
{
	return _position;
}

team Piece::getSide() const
{
	return _side;
}

void Piece::setPosition(const std::string& position)
{
	const int x = position[0] - 'A';
	const int y = '8' - position[1];
	_sprite.setPosition(x * 100.f, y * 100.f);
}

void Piece::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}