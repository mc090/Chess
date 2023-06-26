#pragma once

import Enum;

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

	// Konstruktor
	Clock(sf::Vector2f position);

	// Startuje zegar
	void start();

	// Zatrzymuje zegar
	void pause();

	// Ustala początkowy czas gracza
	void restart();

	// Ustala czas gracza
	void setTime(int time);

	// Zwraca liczbę pozostałych sekund
	int getRemainigTime() const;

	// Pokazuje zegar na ekranie
	void draw(sf::RenderWindow* window);
};
