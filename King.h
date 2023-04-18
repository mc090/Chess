#pragma once

#include "Piece.h"

class King : public Piece
{

public:
	King(const std::string& position, team side);
	~King() override = default;
	void move() override;
};