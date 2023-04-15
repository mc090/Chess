#pragma once

#include "Piece.h"

class King : public Piece
{

public:
	King(int x, int y, Team side);
	void Move() override;
};