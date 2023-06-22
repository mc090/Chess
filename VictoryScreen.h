#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Enum.h"

class VictoryScreen
{
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	explicit VictoryScreen(const gameResult& game_result);
	void draw(sf::RenderWindow* window) const;
};
