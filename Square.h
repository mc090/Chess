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

	// £aduje teksturê z pliku
	void initializeSprite();

	// Ustala pole na wartoœci domyœlne
	void reset();

	// Zmienia kolor pola na kolor reprezentuj¹cy zaznaczenie
	void setSelectedColor();

	// Zmienia kolor pola na kolor reprezentuj¹cy szach
	void setCheckColor();

protected:
	sf::RectangleShape _sprite;

public:

	// Konstruktor
	explicit Square(const Position& position);

	// Destruktor
	virtual ~Square() = default;

	// Zmienia kolor pola na domyœlny
	virtual void setDefaultColor();

	// Zmienia kolor pola na kolor reprezentuj¹cy ostatni wykonany ruch
	virtual void setLastMoveColor() = 0;

	// Oznacza mo¿liwoœæ wykonania ruchu
	virtual void markAsAvaliableMove();

	// Ustala wartoœæ zmiennej _is_occupied
	void setIsOccupied(bool is_occupied);

	// Ustala wartoœæ zmiennej _is_selected
	void setIsSelected(bool is_selected);

	// Ustala wartoœæ zmiennej _is_en_passant_possible
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

