#pragma once
#include "Square.h"

class SquareWhite final : public Square
{
public:

	// Konstruktor
	explicit SquareWhite(const Position& position);

	// Destruktor
	~SquareWhite() override = default;

	// Zmienia kolor pola na domyœlny
	void setDefaultColor() override;

	// Zmienia kolor pola na kolor reprezentuj¹cy ostatni wykonany ruch
	void setLastMoveColor() override;
};