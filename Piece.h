#pragma once

#include "Position.h"
import Enum;

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>


class Piece
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	team _side;
	Position _position;
	std::vector<Position> _available_moves;
	bool _is_starting_position;

	// Ustala startow� pozycj� bierki
	void initializePosition();

public:

	// Konstruktor
	Piece(team side, const std::string& position);

	// Destruktor
	virtual ~Piece() = default;

	// Zwraca aktualn� pozycj� bierki
	Position getPosition() const;

	// Zwraca kolor bierki
	team getSide() const;

	// Zwraca informacj� czy bierka jest na pozycji pocz�tkowej
	bool getIsStartingPosition() const;

	// Ustala now� pozycj� bierki
	void setPosition(const Position& position);

	// Ustala bierce status zbitej
	void setToDelete(int& taken_black, int& taken_white);

	// Zwraca informacj� czy bierka zosta�a zbita
	bool isToDelete() const;

	// Ustala nowy kolor bierki
	void setSide(team side);

	// Zwraca wektor potencjalnych pozycji ko�cowych
	virtual std::vector<Position> getPotentialDestinations() = 0;

	// Zwraca wektor pozycji prowadz�cych do pozycji ko�cowej
	virtual std::vector<Position> setPathTo(const Position& destination) = 0;

	// Zwraca wektor dost�pnych pozycji
	std::vector<Position> getAvailableMoves();

	// Ustala wektor dostepnych pozycji
	void setAvaliableMoves(const std::vector<Position>& moves);

	// Ustala wektor dostepnych pozycji na pusty
	void clearAvaliableMoves();

	// Pokazuje bierk� na ekranie
	void draw(sf::RenderWindow* window) const;

	// Zmienia startow� pozycj� na false
	void setStartingPositionFalse();
};

