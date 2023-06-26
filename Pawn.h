#pragma once

#include "Piece.h"

class Pawn final : public Piece
{
	// �aduje tekstur� z pliku
	void initializeTexture();

public:

	// Konstruktor
	Pawn(team side, const std::string& position);

	// Destruktor
	~Pawn() override = default;

	// Zwraca wektor potencjalnych pozycji ko�cowych
	std::vector<Position> getPotentialDestinations() override;

	// Zwraca wektor pozycji prowadz�cych do pozycji ko�cowej
	std::vector<Position> setPathTo(const Position& destination) override;
};