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
	setPosition(position);
}



std::vector<std::string> King::getPotentialDestinations()
{
	std::vector<std::string> potential_moves;
	return potential_moves;
}

std::vector<std::string> King::getPathTo(std::string position, const std::string& destination)
{
	std::vector<std::string> path;
	return path;
}