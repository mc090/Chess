#pragma once

#include "Piece.h"

class Queen : public Piece
{

public:
	Queen(const std::string& position, team side);
	~Queen() override = default;
	void move() override;
};