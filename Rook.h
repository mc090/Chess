#pragma once

#include "Piece.h"

class Rook final : public Piece
{
	void initializeTexture();

public:
	Rook(const team side, const std::string& position);
	~Rook() override = default;

	std::vector<Position> getPotentialDestinations() override;
	virtual std::vector<Position> getPathTo(const Position& destination) override;
};