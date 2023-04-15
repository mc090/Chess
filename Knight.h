#pragma once

#include "Piece.h"

class Knight : public Piece
{

public:
	Knight(int x, int y, Team side);
	void Move() override;
};