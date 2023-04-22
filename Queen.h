#pragma once

#include "Piece.h"

class Queen final : public Piece
{
	void initializeTexture();

public:
	Queen(const team side, const std::string& position);
	~Queen() override = default;

	std::vector<std::string> getPotentialDestinations() override;
	virtual std::vector<std::string> getPathTo(std::string position, const std::string& destination) override;
};