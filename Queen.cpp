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
	setPosition(position);
}


std::vector<std::string> Queen::getPotentialMoves()
{
	std::vector<std::string> potential_moves;
	return potential_moves;
}

std::vector<std::string> Queen::getPathTo(std::string position, const std::string& destination)
{
	std::vector<std::string> path;
	return path;
}

void Queen::move(std::vector<std::string> potential_moves)
{
}
