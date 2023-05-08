#pragma once

#include "Piece.h"

class Bishop final : public Piece
{
	void initializeTexture();

public:
	Bishop(const team side, const std::string& position);
	~Bishop() override = default ;

	void getMove(std::vector<Position>& potential_destinations, const int& i, const int& j) const;
	std::vector<Position> getPotentialDestinations() override;
	virtual std::vector<Position> setPathTo(const Position& destination) override;
};