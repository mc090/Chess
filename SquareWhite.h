#pragma once
#include "Square.h"
class SquareWhite : public Square
{
public:
	SquareWhite(int x, int y);

	void Default() override;
	void Position() override;
	void Move() override;
};

