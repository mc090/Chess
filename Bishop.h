#pragma once

#include "Piece.h"

class Bishop : public Piece
{

public:
	Bishop(const std::string& position, team side);
	~Bishop() override = default ;
	void move() override;
};