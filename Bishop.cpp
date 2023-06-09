#include "Bishop.h"

void Bishop::initializeTexture()
{
	if (_side)
	{
		this->_texture.loadFromFile("Textures/BlackBishop.png");
	}
	else
	{
		this->_texture.loadFromFile("Textures/WhiteBishop.png");
	}
	this->_sprite.setTexture(this->_texture);
}



Bishop::Bishop(const team side, const std::string& position) : Piece(side, position)
{
	initializeTexture();
	initializePosition();
}


void Bishop::getMove(std::vector<Position>& potential_destinations, const int& x, const int& y) const
{
	char column = _position.getColumn();
	char row = _position.getRow();
	do
	{
		column += x;
		row += y;
		if (column < 'A' or column > 'H' or row < '1' or row > '8')
		{
			const Position position(column - x, row - y);
			if (position.get() != _position.get())
			{
				potential_destinations.push_back(position);
			}
			break;
		}
	} while (true);
}

std::vector<Position> Bishop::getPotentialDestinations()
{
	std::vector<Position> potential_destinations;
	getMove(potential_destinations, -1, -1);
	getMove(potential_destinations, -1, 1);
	getMove(potential_destinations, 1, -1);
	getMove(potential_destinations, 1, 1);
	return potential_destinations;
}

std::vector<Position> Bishop::setPathTo(const Position& destination)
{
	std::vector<Position> path;
	char column = _position.getColumn();
	char row = _position.getRow();
	const int i = destination.getColumn() - column > 0 ? 1 : -1;
	const int j = destination.getRow() - row > 0 ? 1 : -1;
	do
	{
		column += i;
		row += j;
		const Position position(column, row);
		path.push_back(position);
	} while (column != destination.getColumn() and row != destination.getRow());
	return path;
}