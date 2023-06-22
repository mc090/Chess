#pragma once

#include "Enum.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Clock
{
	sf::Clock _clock;
	sf::Font _font;
	sf::Text _text;
	bool _is_clock_started;
	int _time_when_stopped;

public:
	Clock(sf::Vector2f position);
	void start();
	void pause();
	void restart();
	int getRemainigTime() const;
	void draw(sf::RenderWindow* window);
};
