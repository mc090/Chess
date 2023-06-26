#pragma once
#include "Square.h"

class SquareBlack final : public Square
{
public:

	// Konstruktor
	explicit SquareBlack(const Position& position);

	// Destruktor
	~SquareBlack() override = default;

	// Zmienia kolor pola na domy�lny
	void setDefaultColor() override;

	// Zmienia kolor pola na kolor reprezentuj�cy ostatni wykonany ruch
	void setLastMoveColor() override;
};