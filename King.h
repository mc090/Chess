#pragma once

#include "Piece.h"

class King final : public Piece
{
	// �aduje tekstur� z pliku
	void initializeTexture();

	// Dodaje do wektora potencjaln� pozycje ko�cow� w kierunku okro�lonym przez zmienne "x" oraz "y"
	void getMove(std::vector<Position>& potential_destinations, const int& x, const int& y) const;

	// Dodaje do wektora pozycje umo�liwiaj�ce wykonanie roszady
	void castling(std::vector<Position>& potential_destinations) const;

public:

	// Konstruktor
	King(team side, const std::string& position);

	// Destruktor
	~King() override = default;

	// Zwraca prawd� kiedy kr�l jest atakowany
	void isCheck(bool check);

	// Zwraca wektor potencjalnych pozycji ko�cowych
	std::vector<Position> getPotentialDestinations() override;

	// Zwraca wektor pozycji prowadz�cych do pozycji ko�cowej
	std::vector<Position> setPathTo(const Position& destination) override;
};