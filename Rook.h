#pragma once

#include "Piece.h"

class Rook : public Piece
{

public:
	Rook(const std::string& position, team side);
	void move() override;
};