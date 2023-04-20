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
	setPosition(position);
}



std::vector<std::string> Knight::getPotentialMoves()
{
	std::vector<std::string> potential_moves;
	return potential_moves;
}

std::vector<std::string> Knight::getPathTo(std::string position, const std::string& destination)
{
	std::vector<std::string> path;
	return path;
}

void Knight::move(std::vector<std::string> potential_moves)
{
}
