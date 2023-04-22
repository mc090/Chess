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
	_position = position;
	_sprite.setPosition(x * 100.f, y * 100.f);
}

void Piece::setToDelete(int& taken_black, int& taken_white)
{
	_position = _side ? "GG" : "FF";
	const int count = _side ? taken_black++ : taken_white++;
	const float y = _side ? 700.f : 20.f;
	_sprite.setPosition(840.f + ((count % 8) * 40.f), y + (count / 8) * 40);
	const sf::Vector2f target_size(40, 40);
	_sprite.setScale(
		target_size.x / _sprite.getGlobalBounds().width,
		target_size.y / _sprite.getGlobalBounds().height
	);
		_side = taken;
}

bool Piece::isToDelete() const
{
	return _side == taken ? true : false;
}

void Piece::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}
