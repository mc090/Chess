#pragma once

#include "Enum.h"
#include "Position.h"

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


class Piece
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	team _side;
	Position _position;
	std::vector<Position> _available_moves;

	void initializePosition();

public:
	Piece(team side, const std::string& position);
	virtual ~Piece() = default;

	Position getPosition() const;
	team getSide() const;
	void setPosition(const Position& position);
	void setToDelete(int& taken_black, int& taken_white);
	bool isToDelete() const;

	virtual std::vector<Position> getPotentialDestinations() = 0;
	virtual std::vector<Position> setPathTo(const Position& destination) = 0;
	std::vector<Position> getAvailableMoves();
	void setAvaliableMoves(const std::vector<Position>& moves);

	void draw(sf::RenderWindow* window) const;
};

