#pragma once

#include "Piece.h"

class Rook final : public Piece
{
	void initializeTexture();

public:
	Rook(const team side, const std::string& position);
	~Rook() override = default;

	std::vector<std::string> getPotentialDestinations() override;
	virtual std::vector<std::string> getPathTo(std::string position, const std::string& destination) override;
};