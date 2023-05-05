#pragma once

#include "Piece.h"

class Rook final : public Piece
{
	void initializeTexture();

public:
	Rook(const team side, const std::string& position);
	~Rook() override = default;

	void getMove(std::vector<Position>& potential_destinations, const int& i, const int& j) const;
	std::vector<Position> getPotentialDestinations() override;
	virtual std::vector<Position> getPathTo(const Position& destination) override;
};