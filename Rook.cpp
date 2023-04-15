#include "Rook.h"

Rook::Rook(int x, int y, Team side) : Piece(x, y, side)
{
	std::string Side = side ? "Black" : "White";
	this->texture.loadFromFile("Textures/" + Side + "Rook.png");
	this->sprite.setTexture(this->texture);
	SetPosition(x, y);
}

void Rook::Move()
{
}
