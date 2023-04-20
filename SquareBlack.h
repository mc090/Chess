#pragma once
#include "Square.h"
class SquareBlack : public Square
{
public:
	explicit SquareBlack(const std::string& position);
	~SquareBlack() override = default;

	void setDefaultColor() override;
	void setPositionColor() override;
	void setPotenitalMoveColor() override;
};

