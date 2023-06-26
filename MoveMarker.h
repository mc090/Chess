#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class MoveMarker
{
	sf::CircleShape _sprite;

public:

	// Konstruktor
	MoveMarker(int x, int y, float radius);

	// Pokazuje znacznik ruchu na ekranie
	void draw(sf::RenderWindow* window) const;
};

