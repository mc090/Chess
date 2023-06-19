#include "King.h"

void King::initializeTexture()
{
	const std::string team = _side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "King.png");
	this->_sprite.setTexture(this->_texture);
}

void King::castling(std::vector<Position>& potential_destinations) const 
{
	if (_side)
	{
		const Position first("C8");
		const Position second("G8");
		potential_destinations.push_back(first);
		potential_destinations.push_back(second);
	}
	else
	{
		const Position first("C1");
		const Position second("G1");
		potential_destinations.push_back(first);
		potential_destinations.push_back(second);
	}
}


King::King(const team side, const std::string& position) :Piece(side, position)
{
	initializeTexture();
	initializePosition();
}


void King::getMove(std::vector<Position>& potential_destinations, const int& i, const int& j) const
{
	const char column = _position.getColumn() + i;
	const char row = _position.getRow() + j;
	if (column > '@' and column < 'I' and row > '0' and row < '9')
	{
		const Position position(column, row);
		if (position.get() != _position.get())
		{
			potential_destinations.push_back(position);
		}
	}
}

void King::isCheck(const bool check)
{
	check ? _sprite.setColor(sf::Color::Red) : _sprite.setColor(sf::Color::White);
}

std::vector<Position> King::getPotentialDestinations()
{
	std::vector<Position> potential_destinations;
	getMove(potential_destinations, -1, -1);
	getMove(potential_destinations, -1, 0);
	getMove(potential_destinations, 0, -1);
	getMove(potential_destinations, -1, 1);
	getMove(potential_destinations, 1, -1);
	getMove(potential_destinations, 0, 1);
	getMove(potential_destinations, 1, 0);
	getMove(potential_destinations, 1, 1);
	if (_is_starting_position)
	{
		castling(potential_destinations);
	}
	return potential_destinations;
}

std::vector<Position> King::setPathTo(const Position& destination)
{
	std::vector<Position> path;
	path.push_back(destination);
	return path;
}