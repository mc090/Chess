#include "PawnPromotion.h"

PawnPromotion::PawnPromotion(const team turn)
{
	const std::string team = turn ? "Black" : "White";
	_texture.loadFromFile("Textures/" + team + "Transformation.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(150.f, 337.5);
}

void PawnPromotion::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}