#include "Queen.h"

Queen::Queen(int x, int y, Team side) : Piece(x, y, side)
{
	std::string Side = side ? "Black" : "White";
	this->texture.loadFromFile("Textures/" + Side + "Queen.png");
	this->sprite.setTexture(this->texture);
	SetPosition(x, y);
}

void Queen::Move()
{
}
