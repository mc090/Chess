#pragma once

#include "Piece.h"

class Pawn final : public Piece
{
	void initializeTexture();

public:
	Pawn(const team side, const std::string& position);
	~Pawn() override = default;

	std::vector<Position> getPotentialDestinations() override;
	std::vector<Position> setPathTo(const Position& destination) override;
};