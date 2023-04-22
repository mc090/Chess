#pragma once
#include "Square.h"

class SquareWhite : public Square
{
public:
	explicit SquareWhite(const std::string& position);
	~SquareWhite() override = default;

	void setDefaultColor() override;
	void setPositionColor() override;
	void setPotenitalMoveColor() override;
};