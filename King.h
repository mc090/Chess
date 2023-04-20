#pragma once

#include "Piece.h"

class King final : public Piece
{
	void initializeTexture();

public:
	King(const team side, const std::string& position);
	~King() override = default;

	std::vector<std::string> getPotentialMoves() override;
	virtual std::vector<std::string> getPathTo(std::string position, const std::string& destination) override;
	void move(std::vector<std::string> potential_moves) override;
};