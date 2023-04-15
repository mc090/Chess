#include "King.h"

King::King(int x, int y, Team side) :Piece(x, y, side)
{
	std::string Side = side ? "Black" : "White";
	this->texture.loadFromFile("Textures/" + Side + "King.png");
	this->sprite.setTexture(this->texture);
	SetPosition(x, y);
}

void King::Move()
{
}
