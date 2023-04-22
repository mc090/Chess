#pragma once

#include "Piece.h"

class Knight : public Piece
{
	void initializeTexture();

public:
	Knight(const team side, const std::string& position);
	~Knight() override = default;

	std::vector<std::string> getPotentialDestinations() override;
	virtual std::vector<std::string> getPathTo(std::string position, const std::string& destination) override;
};