#pragma once

#include "Piece.h"

class Pawn final : public Piece
{
	// £aduje teksturê z pliku
	void initializeTexture();

public:

	// Konstruktor
	Pawn(team side, const std::string& position);

	// Destruktor
	~Pawn() override = default;

	// Zwraca wektor potencjalnych pozycji koñcowych
	std::vector<Position> getPotentialDestinations() override;

	// Zwraca wektor pozycji prowadz¹cych do pozycji koñcowej
	std::vector<Position> setPathTo(const Position& destination) override;
};