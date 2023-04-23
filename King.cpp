#include "King.h"

void King::initializeTexture()
{
	const std::string team = _side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "King.png");
	this->_sprite.setTexture(this->_texture);
}



King::King(const team side, const std::string& position) :Piece(side, position)
{
	initializeTexture();
	initializePosition();
}



std::vector<Position> King::getPotentialDestinations()
{
	std::vector<Position> potential_destinations;
	for (int i = -1; i < 2; i += 2)
	{
		char column = _position.getColumn();
		char row = _position.getRow();
		column += i;
		if (column < 'I' and column > '@')
		{
			const Position position(column, row);
			if (position.get() != _position.get())
			{
				potential_destinations.push_back(position);
			}
		}
		column = _position.getColumn();
		row += i;
		if (row < '9' and row > '0')
		{
			const Position position(column, row);
			if (position.get() != _position.get())
			{
				potential_destinations.push_back(position);
			}
		}
	}
	for (int i = -1; i < 2; i += 2)
	{
		for (int j = -1; j < 2; j += 2)
		{
			char column = _position.getColumn();
			char row = _position.getRow();
			column += i;
			row += j;
			if (column < 'I' and column > '@' and row < '9' and row > '0')
			{
				const Position position(column, row);
				if (position.get() != _position.get())
				{
					potential_destinations.push_back(position);
				}
			}
		}
	}
	return potential_destinations;
}

std::vector<Position> King::getPathTo(const Position& destination)
{
	std::vector<Position> path;
	path.push_back(destination);
	return path;
}