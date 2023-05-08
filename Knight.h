#pragma once

#include "Piece.h"

class Knight final : public Piece
{
	void initializeTexture();

public:
	Knight(const team side, const std::string& position);
	~Knight() override = default;

	void getMove(std::vector<Position>& potential_destinations, const int& i,const int& j) const;
	std::vector<Position> getPotentialDestinations() override;
	virtual std::vector<Position> setPathTo(const Position& destination) override;
};