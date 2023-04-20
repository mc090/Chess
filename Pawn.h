#pragma once

#include "Piece.h"

class Pawn final : public Piece
{
	bool _is_starting_position;

	void initializeTexture();

public:
	Pawn(const team side, const std::string& position);
	~Pawn() override = default;

	void setStartingPositionFalse();

	std::vector<std::string> getPotentialMoves() override;
	std::vector<std::string> getPathTo(std::string position, const std::string& destination) override;
	void move(std::vector<std::string> potential_moves) override;
};