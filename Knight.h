#pragma once

#include "Piece.h"

class Knight final : public Piece
{
	// �aduje tekstur� z pliku
	void initializeTexture();

	// Dodaje do wektora potencjaln� pozycje ko�cow� w kierunku okro�lonym przez zmienne "x" oraz "y"
	void getMove(std::vector<Position>& potential_destinations, const int& x,const int& y) const;

public:

	// Konstruktor
	Knight(team side, const std::string& position);

	// Destruktor
	~Knight() override = default;

	// Zwraca wektor potencjalnych pozycji ko�cowych
	std::vector<Position> getPotentialDestinations() override;

	// Zwraca wektor pozycji prowadz�cych do pozycji ko�cowej
	std::vector<Position> setPathTo(const Position& destination) override;
};