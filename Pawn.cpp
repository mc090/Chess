#include "Pawn.h"

void Pawn::initializeTexture()
{
	const std::string team = _side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "Pawn.png");
	this->_sprite.setTexture(this->_texture);
}



Pawn::Pawn(const team side, const std::string& position) :Piece(side, position)
{
	initializeTexture();
	initializePosition();
}


std::vector<Position> Pawn::getPotentialDestinations()
{
	std::vector<Position> potential_moves;
	const char column = _position.getColumn();
	const char row = _position.getRow();
	if (row != '1' and row != '8')
	{
		int i = (column == 'A' ? 0 : -1);
		const int max_column = (column == 'H' ? 1 : 2);
		for (; i < max_column; i++)
		{
			const Position position(char(column + i), char(_side ? (row - 1) : (row + 1)));
			potential_moves.push_back(position);
		}
		if (_is_starting_position)
		{
			const Position position(column, char(_side ? (row - 2) : (row + 2)));
			potential_moves.push_back(position);
		}
		else
		{
			const Position position(column, char(_side ? (row - 1) : (row + 1)));
			potential_moves.push_back(position);
		}
	}
	return potential_moves;
}

std::vector<Position> Pawn::setPathTo(const Position& destination)
{
	std::vector<Position> path;
	const char column = _position.getColumn();
	char row = _position.getRow();
	if (destination.getColumn() == column + 1 or destination.getColumn() == column - 1)
	{
		path.push_back(destination);

	}
	else
	{
		do
		{
			_side ? row-- : row++;
			Position checked_positon(column, row);
			path.push_back(checked_positon);

		} while (row != destination.getRow());
	}
	return path;
}