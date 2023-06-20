#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Enum.h"

class PawnPromotion
{
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	explicit PawnPromotion(team turn);
	void draw(sf::RenderWindow* window) const;
};
