#pragma once
#include "Square.h"
class SquareBlack : public Square
{
public:
	SquareBlack(int x, int y);

	void Default() override;
	void Position() override;
	void Move() override;
};

