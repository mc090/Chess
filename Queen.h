#pragma once

#include "Piece.h"

class Queen final : public Piece
{
	// £aduje teksturê z pliku
	void initializeTexture();

	// Dodaje do wektora potencjaln¹ pozycje koñcow¹ w kierunku okroœlonym przez zmienne "x" oraz "y"
	void getMove(std::vector<Position>& potential_destinations, const int& x, const int& y) const;

public:

	// Konstruktor
	Queen(team side, const std::string& position);

	// Destruktor
	~Queen() override = default;

	// Zwraca wektor potencjalnych pozycji koñcowych
	std::vector<Position> getPotentialDestinations() override;

	// Zwraca wektor pozycji prowadz¹cych do pozycji koñcowej
	std::vector<Position> setPathTo(const Position& destination) override;
};