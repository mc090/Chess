#include "Bishop.h"

Bishop::Bishop(const std::string& position,const team side) : Piece(position, side)
{
	const std::string team = side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "Bishop.png");
	this->_sprite.setTexture(this->_texture);
	setPosition(position);
}

void Bishop::move()
{
}
