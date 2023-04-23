#pragma once

#include "Piece.h"

class Bishop final : public Piece
{
	void initializeTexture();

public:
	Bishop(const team side, const std::string& position);
	~Bishop() override = default ;

	std::vector<Position> getPotentialDestinations() override;
	virtual std::vector<Position> getPathTo(const Position& destination) override;
};