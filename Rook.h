#pragma once

#include "Piece.h"

class Rook : public Piece
{

public:
	Rook(int x, int y, Team side);
	void Move() override;
};