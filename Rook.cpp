#include "Rook.h"

void Rook::initializeTexture()
{
	const std::string team = _side ? "Black" : "White";
	_texture.loadFromFile("Textures/" + team + "Rook.png");
	_sprite.setTexture(_texture);
}



Rook::Rook(const team side, const std::string& position) :Piece(side, position)
{
	initializeTexture();
	initializePosition();
}


void Rook::getMove(std::vector<Position>& potential_destinations, const int& x, const int& y) const
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

std::vector<Position> Rook::getPotentialDestinations()
{
	std::vector<Position> potential_destinations;
	getMove(potential_destinations, -1, 0);
	getMove(potential_destinations, 0, -1);
	getMove(potential_destinations, 0, 1);
	getMove(potential_destinations, 1, 0);
	return potential_destinations;
}

std::vector<Position> Rook::setPathTo(const Position& destination)
{
	std::vector<Position> path;
	char column = _position.getColumn();
	char row = _position.getRow();
	Position position(column, row);
	const int i = destination.getColumn() - column == 0 ? 0 : destination.getColumn() - column > 0 ? 1 : -1;
	const int j = destination.getRow() - row == 0 ? 0 : destination.getRow() - row > 0 ? 1 : -1;
	do
	{
		column += i;
		row += j;
		position.set(column, row);
		path.push_back(position);
	} while (position.get() != destination.get());
	return path;
}
