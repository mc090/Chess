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

	// Ustala startow¹ pozycjê bierki
	void initializePosition();

public:

	// Konstruktor
	Piece(team side, const std::string& position);

	// Destruktor
	virtual ~Piece() = default;

	// Zwraca aktualn¹ pozycjê bierki
	Position getPosition() const;

	// Zwraca kolor bierki
	team getSide() const;

	// Zwraca informacjê czy bierka jest na pozycji pocz¹tkowej
	bool getIsStartingPosition() const;

	// Ustala now¹ pozycjê bierki
	void setPosition(const Position& position);

	// Ustala bierce status zbitej
	void setToDelete(int& taken_black, int& taken_white);

	// Zwraca informacjê czy bierka zosta³a zbita
	bool isToDelete() const;

	// Ustala nowy kolor bierki
	void setSide(team side);

	// Zwraca wektor potencjalnych pozycji koñcowych
	virtual std::vector<Position> getPotentialDestinations() = 0;

	// Zwraca wektor pozycji prowadz¹cych do pozycji koñcowej
	virtual std::vector<Position> setPathTo(const Position& destination) = 0;

	// Zwraca wektor dostêpnych pozycji
	std::vector<Position> getAvailableMoves();

	// Ustala wektor dostepnych pozycji
	void setAvaliableMoves(const std::vector<Position>& moves);

	// Ustala wektor dostepnych pozycji na pusty
	void clearAvaliableMoves();

	// Pokazuje bierkê na ekranie
	void draw(sf::RenderWindow* window) const;

	// Zmienia startow¹ pozycjê na false
	void setStartingPositionFalse();
};

