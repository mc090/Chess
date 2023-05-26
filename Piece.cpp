#include "Piece.h"


void Piece::initializePosition()
{
	const int x = _position.getColumn() - 'A';
	const int y = '8' - _position.getRow();
	_sprite.setPosition(x * 100.f, y * 100.f);
}

Piece::Piece(const team side, const std::string& position) :_side(side), _position(position)
{
}

Position Piece::getPosition() const
{
	return _position;
}

team Piece::getSide() const
{
	return _side;
}

void Piece::setPosition(const Position& position)
{
	_position = position;
	const int x = position.getColumn() - 'A';
	const int y = '8' - position.getRow();
	_sprite.setPosition(x * 100.f, y * 100.f);
}

void Piece::setToDelete(int& taken_black, int& taken_white)
{
	_position.set(_side ? "GG" : "FF");
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

void Piece::setSide(const team side)
{
	_side = side;
}

std::vector<Position> Piece::getAvailableMoves()
{
	return _available_moves;
}

void Piece::setAvaliableMoves(const std::vector<Position>& moves)
{
	_available_moves = moves;
}

void Piece::clearAvaliableMoves()
{
	_available_moves.clear();
}

void Piece::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}
