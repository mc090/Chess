#include "Pawn.h"

void Pawn::initializeTexture()
{
	const std::string team = _side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "Pawn.png");
	this->_sprite.setTexture(this->_texture);
}



Pawn::Pawn(const team side, const std::string& position) :Piece(side, position), _is_starting_position(true)
{
	initializeTexture();
	setPosition(position);
}


void Pawn::setStartingPositionFalse()
{
	_is_starting_position = false;
}


void Pawn::setIsStartingPosition(const bool is_starting_position)
{
	_is_starting_position = is_starting_position;
}



std::vector<std::string> Pawn::getPotentialDestinations()
{
	std::vector<std::string> potential_moves;
	const char column = _position[0];
	const char row = _position[1];
	if (row != '1' and row != '8')
	{
		int i = (column == 'A' ? 0 : -1);
		const int max_column = (column == 'H' ? 1 : 2);
		for (; i < max_column; i++)
		{
			std::string position;
			position += column + i;
			position += (_side ? (row - 1) : (row + 1));
			potential_moves.push_back(position);
		}
		if (_is_starting_position)
		{
			std::string position;
			position += column;
			position += (_side ? (row - 2) : (row + 2));
			potential_moves.push_back(position);
		}
		else
		{
			std::string position;
			position += column;
			position += (_side ? (row - 1) : (row + 1));
			potential_moves.push_back(position);
		}
	}
	return potential_moves;
}

std::vector<std::string> Pawn::getPathTo(std::string position, const std::string& destination)
{
	std::vector<std::string> path;
	if (destination[0] == position[0] + 1 or destination[0] == position[0] - 1)
	{
		path.push_back(destination);

	}
	else
	{
		do
		{
			std::string checked_positon;
			_side ? position[1]-- : position[1]++;
			checked_positon += position[0];
			checked_positon += position[1];
			path.push_back(checked_positon);

		} while (position != destination);
	}
	return path;
}