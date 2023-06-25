#pragma once

#include "Position.h"
import Enum;

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>


class Piece
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	team _side;
	Position _position;
	std::vector<Position> _available_moves;
	bool _is_starting_position;

	void initializePosition();

public:
	Piece(team side, const std::string& position);
	virtual ~Piece() = default;

	Position getPosition() const;
	team getSide() const;
	bool getIsStartingPosition() const;
	void setPosition(const Position& position);
	void setToDelete(int& taken_black, int& taken_white);
	bool isToDelete() const;
	void setSide(team side);

	virtual std::vector<Position> getPotentialDestinations() = 0;
	virtual std::vector<Position> setPathTo(const Position& destination) = 0;
	std::vector<Position> getAvailableMoves();
	void setAvaliableMoves(const std::vector<Position>& moves);
	void clearAvaliableMoves();

	void draw(sf::RenderWindow* window) const;

	void setStartingPositionFalse();
};

