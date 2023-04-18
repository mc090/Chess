#include "Pawn.h"

Pawn::Pawn(const std::string& position, const team side) :Piece(position, side)
{
	const std::string team = side ? "Black" : "White";
	this->_texture.loadFromFile("Textures/" + team + "Pawn.png");
	this->_sprite.setTexture(this->_texture);
	setPosition(position);
}

void Pawn::move()
{
}
