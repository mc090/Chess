#include "Queen.h"

void Queen::initializeTexture()
{
	const std::string team = _side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "Queen.png");
	this->_sprite.setTexture(this->_texture);
}



Queen::Queen(const team side,const std::string& position) :Piece(side,position)
{
	initializeTexture();
	initializePosition();
}


std::vector<Position> Queen::getPotentialDestinations()
{
	std::vector<Position> potential_destinations;
	for (int i = -1; i < 2; i += 2)
	{
		char column = _position.getColumn();
		char row = _position.getRow();
		do
		{
			column += i;
			if (column < 'A' or column > 'H')
			{
				const Position position(column - i, row);
				if (position.get() != _position.get())
				{
					potential_destinations.push_back(position);
				}
				break;
			}

		} while (true);
		column = _position.getColumn();
		do
		{

			row += i;
			if (row < '1' or row > '8')
			{
				const Position position(column, row - i);
				if (position.get() != _position.get())
				{
					potential_destinations.push_back(position);
				}
				break;
			}

		} while (true);
	}
	for (int i = -1; i < 2; i += 2)
	{
		for (int j = -1; j < 2; j += 2)
		{
			char column = _position.getColumn();
			char row = _position.getRow();
			do
			{
				column += i;
				row += j;
				if (column < 'A' or column > 'H' or row < '1' or row > '8')
				{
					const Position position(column - i, row - j);
					if (position.get() != _position.get())
					{
						potential_destinations.push_back(position);
					}
					break;
				}
			} while (true);
		}
	}
	return potential_destinations;
}

std::vector<Position> Queen::getPathTo(const Position& destination)
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
