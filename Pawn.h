#pragma once

#include "Piece.h"

class Pawn : public Piece
{

public:
	Pawn(const std::string& position, team side);
	~Pawn() override = default;
	void move() override;
};