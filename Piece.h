#pragma once

#include "Enum.h"
#include "Position.h"

#include <iostream>

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
	virtual std::vector<Position> getPathTo(const Position& destination) = 0;

	void draw(sf::RenderWindow* window) const;
};

