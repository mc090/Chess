#include "Square.h"

void Square::InitializeSprite()
{
	sprite.setSize(sf::Vector2f(100.f, 100.f));
	sprite.setPosition(x * 100.f, y * 100.f);
}


void Square::Draw(sf::RenderWindow* window)
{
    window->draw(this->sprite);
}
