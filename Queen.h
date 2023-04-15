#pragma once

#include "Piece.h"

class Queen : public Piece
{

public:
	Queen(int x, int y, Team side);
	void Move() override;
};