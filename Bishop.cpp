#include "Bishop.h"

void Bishop::initializeTexture()
{
	const std::string team = _side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "Bishop.png");
	this->_sprite.setTexture(this->_texture);
}



Bishop::Bishop(const team side, const std::string& position) : Piece(side, position)
{
	initializeTexture();
	setPosition(position);
}



std::vector<std::string> Bishop::getPotentialMoves()
{
	std::vector<std::string> potential_moves;
	return potential_moves;
}

std::vector<std::string> Bishop::getPathTo(std::string position, const std::string& destination)
{
	std::vector<std::string> path;
	return path;
}

void Bishop::move(std::vector<std::string> potential_moves)
{
}
