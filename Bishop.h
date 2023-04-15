#pragma once

#include "Piece.h"

class Bishop : public Piece
{

public:
	Bishop(int x, int y, Team side);
	void Move() override;
};