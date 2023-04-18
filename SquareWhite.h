#pragma once
#include "Square.h"
class SquareWhite : public Square
{
public:
	explicit SquareWhite(const std::string& position) :Square(position)
	{
		setDefaultColor();
	};
	~SquareWhite() override = default;

	void setDefaultColor() override;
	void setPositionColor() override;
	void setPotenitalMoveColor() override;
};

