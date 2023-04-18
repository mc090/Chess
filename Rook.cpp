#include "Rook.h"

Rook::Rook(const std::string& position, const team side) :Piece(position, side)
{
	const std::string team = side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "Rook.png");
	this->_sprite.setTexture(this->_texture);
	setPosition(position);
}

void Rook::move()
{
}
