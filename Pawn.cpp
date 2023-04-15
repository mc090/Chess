#include "Pawn.h"

Pawn::Pawn(int x, int y, Team side) : Piece(x, y, side)
{
	std::string Side = side ? "Black" : "White";
	this->texture.loadFromFile("Textures/" + Side + "Pawn.png");
	this->sprite.setTexture(this->texture);
	SetPosition(x, y);
}

void Pawn::Move()
{
	if (y != 0 and y != 7) {
		side ? y++ : y--;
		SetPosition(x, y);
	}
}
