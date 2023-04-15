#include "Bishop.h"

Bishop::Bishop(int x, int y, Team side) : Piece(x, y, side)
{
	std::string Side = side ? "Black" : "White";
	this->texture.loadFromFile("Textures/" + Side + "Bishop.png");
	this->sprite.setTexture(this->texture);
	SetPosition(x, y);
}

void Bishop::Move()
{
}
