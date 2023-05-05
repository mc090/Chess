#pragma once
#include "Square.h"

class SquareWhite : public Square
{
public:
	explicit SquareWhite(const Position& position);
	~SquareWhite() override = default;

	void setDefaultColor() override;
	void setPositionColor() override;
};