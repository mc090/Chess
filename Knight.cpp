#include "Knight.h"

void Knight::initializeTexture()
{
	const std::string team = _side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "Knight.png");
	this->_sprite.setTexture(this->_texture);
}



Knight::Knight(const team side, const std::string& position) :Piece(side, position)
{
	initializeTexture();
	initializePosition();
}


void Knight::getMove(std::vector<Position>& potential_destinations, const int& x, const int& y) const
{
	const char column = _position.getColumn() + x;
	const char row = _position.getRow() + y;
	if (column > '@' and column < 'I' and row > '0' and row < '9') {
		const Position position(column, row);
		potential_destinations.push_back(position);
	}
}

std::vector<Position> Knight::getPotentialDestinations()
{
	std::vector<Position> potential_destinations;
	getMove(potential_destinations, -2, 1);
	getMove(potential_destinations, -2, -1);
	getMove(potential_destinations, -1, 2);
	getMove(potential_destinations, -1, -2);
	getMove(potential_destinations, 1, 2);
	getMove(potential_destinations, 1, -2);
	getMove(potential_destinations, 2, 1);
	getMove(potential_destinations, 2, -1);
	return potential_destinations;
}

std::vector<Position> Knight::setPathTo(const Position& destination)
{
	std::vector<Position> path;
	path.push_back(destination);
	return path;
}