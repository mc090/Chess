#pragma once

#include "Piece.h"

class Bishop final : public Piece
{
	void initializeTexture();

public:
	Bishop(const team side, const std::string& position);
	~Bishop() override = default ;

	std::vector<std::string> getPotentialDestinations() override;
	virtual std::vector<std::string> getPathTo(std::string position, const std::string& destination) override;
};