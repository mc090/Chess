#pragma once

#include "Position.h"
#include "MoveMarker.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Square
{
	Position _position;
	MoveMarker* _circle;
	bool _is_move_possible;
	bool _is_selected;
	bool _is_en_passant_possible;
	bool _is_occupied;

	// Ładuje teksturę z pliku
	void initializeSprite();

	// Ustala pole na wartości domyślne
	void reset();

	// Zmienia kolor pola na kolor reprezentujący zaznaczenie
	void setSelectedColor();

	// Zmienia kolor pola na kolor reprezentujący szach
	void setCheckColor();

protected:
	sf::RectangleShape _sprite;

public:

	// Konstruktor
	explicit Square(const Position& position);

	// Destruktor
	virtual ~Square() = default;

	// Zmienia kolor pola na domyślny
	virtual void setDefaultColor();

	// Zmienia kolor pola na kolor reprezentujący ostatni wykonany ruch
	virtual void setLastMoveColor() = 0;

	// Oznacza możliwość wykonania ruchu
	virtual void markAsAvaliableMove();

	// Ustala wartość zmiennej _is_occupied
	void setIsOccupied(bool is_occupied);

	// Ustala wartość zmiennej _is_selected
	void setIsSelected(bool is_selected);

	// Ustala wartość zmiennej _is_en_passant_possible
	void setIsEnPassantPossible(bool is_en_passant_possible);

	// Zwraca wartosc zmiennej _is_occupied
	bool getIsOccupied() const;

	// Zwraca wartosc zmiennej _is_selected
	bool getIsSelected() const;

	// Zwraca wartosc zmiennej _is_move_possible
	bool getIsMovePossible() const;

	// Zwraca wartosc zmiennej _is_en_passant_possible
	bool getIsEnPassantPossible() const;

	// Pokazuje pole na ekranie
	void draw(sf::RenderWindow* window);
};

