#pragma once

#include "Position.h"
#include "MoveMarker.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Square
{
	Position _position;
	MoveMarker* _circle;
	bool _is_selected;
	bool _is_en_passant_possible;
	bool _is_occupied;

	void initializeSprite();

protected:
	sf::RectangleShape _sprite;

public:
	explicit Square(const Position& position);
	virtual ~Square() = default;

	virtual void setDefaultColor();
	void reset();
	virtual void setPositionColor();
	virtual void setAvaliableMoveColor();
	void setCheckColor();
	void setIsOccupied(bool is_occupied);
	bool getIsOccupied() const;
	bool getIsSelected() const;
	bool getIsEnPassantPossible() const;

	void draw(sf::RenderWindow* window) const;
};

