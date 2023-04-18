#pragma once

#include "Piece.h"

class Knight : public Piece
{

public:
	Knight(const std::string& position, team side);
	~Knight() override = default;
	void move() override;
};