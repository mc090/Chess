#pragma once

#include "Piece.h"

class King final : public Piece
{
	void initializeTexture();

public:
	King(const team side, const std::string& position);
	~King() override = default;

	std::vector<Position> getPotentialDestinations() override;
	virtual std::vector<Position> getPathTo(const Position& destination) override;
};