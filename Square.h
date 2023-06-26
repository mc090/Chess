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

	// �aduje tekstur� z pliku
	void initializeSprite();

	// Ustala pole na warto�ci domy�lne
	void reset();

	// Zmienia kolor pola na kolor reprezentuj�cy zaznaczenie
	void setSelectedColor();

	// Zmienia kolor pola na kolor reprezentuj�cy szach
	void setCheckColor();

protected:
	sf::RectangleShape _sprite;

public:

	// Konstruktor
	explicit Square(const Position& position);

	// Destruktor
	virtual ~Square() = default;

	// Zmienia kolor pola na domy�lny
	virtual void setDefaultColor();

	// Zmienia kolor pola na kolor reprezentuj�cy ostatni wykonany ruch
	virtual void setLastMoveColor() = 0;

	// Oznacza mo�liwo�� wykonania ruchu
	virtual void markAsAvaliableMove();

	// Ustala warto�� zmiennej _is_occupied
	void setIsOccupied(bool is_occupied);

	// Ustala warto�� zmiennej _is_selected
	void setIsSelected(bool is_selected);

	// Ustala warto�� zmiennej _is_en_passant_possible
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

