#include "Knight.h"

Knight::Knight(int x, int y, Team side) : Piece(x, y, side)
{
	std::string Side = side ? "Black" : "White";
	this->texture.loadFromFile("Textures/" + Side + "Knight.png");
	this->sprite.setTexture(this->texture);
	SetPosition(x, y);
}

void Knight::Move()
{
}
