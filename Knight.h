#pragma once

#include "Piece.h"

class Knight : public Piece
{
	void initializeTexture();

public:
	Knight(const team side, const std::string& position);
	~Knight() override = default;

	void getMove(std::vector<Position>& potential_destinations, const int& i,const int& j);
	std::vector<Position> getPotentialDestinations() override;
	virtual std::vector<Position> getPathTo(const Position& destination) override;
};