#pragma once

#include "Piece.h"

class King final : public Piece
{
	// £aduje teksturê z pliku
	void initializeTexture();

	// Dodaje do wektora potencjaln¹ pozycje koñcow¹ w kierunku okroœlonym przez zmienne "x" oraz "y"
	void getMove(std::vector<Position>& potential_destinations, const int& x, const int& y) const;

	// Dodaje do wektora pozycje umo¿liwiaj¹ce wykonanie roszady
	void castling(std::vector<Position>& potential_destinations) const;

public:

	// Konstruktor
	King(team side, const std::string& position);

	// Destruktor
	~King() override = default;

	// Zwraca prawdê kiedy król jest atakowany
	void isCheck(bool check);

	// Zwraca wektor potencjalnych pozycji koñcowych
	std::vector<Position> getPotentialDestinations() override;

	// Zwraca wektor pozycji prowadz¹cych do pozycji koñcowej
	std::vector<Position> setPathTo(const Position& destination) override;
};