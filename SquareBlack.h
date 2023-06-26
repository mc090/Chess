#pragma once
#include "Square.h"

class SquareBlack final : public Square
{
public:

	// Konstruktor
	explicit SquareBlack(const Position& position);

	// Destruktor
	~SquareBlack() override = default;

	// Zmienia kolor pola na domyœlny
	void setDefaultColor() override;

	// Zmienia kolor pola na kolor reprezentuj¹cy ostatni wykonany ruch
	void setLastMoveColor() override;
};