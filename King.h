#pragma once

#include "Piece.h"

class King final : public Piece
{
	void initializeTexture();

public:
	King(const team side, const std::string& position);
	~King() override = default;

	void getMove(std::vector<Position>& potential_destinations, const int& i, const int& j) const;
	std::vector<Position> getPotentialDestinations() override;
	std::vector<Position> setPathTo(const Position& destination) override;
};