#pragma once
#include "Square.h"

class SquareWhite final : public Square
{
public:

	// Konstruktor
	explicit SquareWhite(const Position& position);

	// Destruktor
	~SquareWhite() override = default;

	// Zmienia kolor pola na domy�lny
	void setDefaultColor() override;

	// Zmienia kolor pola na kolor reprezentuj�cy ostatni wykonany ruch
	void setLastMoveColor() override;
};