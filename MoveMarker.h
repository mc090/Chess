#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class MoveMarker
{
	sf::CircleShape _sprite;

public:
	MoveMarker(int x, int y, float radius);
	void draw(sf::RenderWindow* window) const;
};

