#pragma once

#include "Piece.h"

class King final : public Piece
{
	void initializeTexture();
	void castling(std::vector<Position>& potential_destinations) const;

public:
	King(const team side, const std::string& position);
	~King() override = default;

	void getMove(std::vector<Position>& potential_destinations, const int& i, const int& j) const;
	void isCheck(bool check);
	std::vector<Position> getPotentialDestinations() override;
	std::vector<Position> setPathTo(const Position& destination) override;
};