#include "Piece.h"


double Piece::GetPosition()
{
	return x + y / 10;
}

void Piece::SetPosition(int x, int y)
{
	this->sprite.setPosition(x * 100.f, y * 100.f);
}

void Piece::Draw(sf::RenderWindow* window)
{
	window->draw(this->sprite);
}
