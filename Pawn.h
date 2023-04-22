#pragma once

#include "Piece.h"

class Pawn final : public Piece
{
	void initializeTexture();
	bool _is_starting_position;

public:
	Pawn(const team side, const std::string& position);
	~Pawn() override = default;

	void setStartingPositionFalse();

	void setIsStartingPosition(const bool is_starting_position);

	std::vector<std::string> getPotentialDestinations() override;
	std::vector<std::string> getPathTo(std::string position, const std::string& destination) override;
	void move(std::vector<std::string> potential_moves) override;
};