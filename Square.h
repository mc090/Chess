#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Square
{
	double x;
	double y;

	void InitializeSprite();

protected:
	sf::RectangleShape sprite;

public:
	Square(int x, int y) :x(x), y(y) {
		InitializeSprite();
	};

	virtual void Default() = 0;
	virtual void Position() = 0;
	virtual void Move() = 0;

	void Draw(sf::RenderWindow* window);
};

