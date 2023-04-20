#pragma once

#include "Piece.h"

class Rook final : public Piece
{
	void initializeTexture();

public:
	Rook(const team side, const std::string& position);
	~Rook() override = default;

	std::vector<std::string> getPotentialMoves() override;
	virtual std::vector<std::string> getPathTo(std::string position, const std::string& destination) override;
	void move(std::vector<std::string> potential_moves) override;
};