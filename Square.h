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
	bool _is_move_possible;
	bool _is_selected;
	bool _is_en_passant_possible;
	bool _is_occupied;

	void initializeSprite();

	void reset();
	void setSelectedColor();
	void setCheckColor();

protected:
	sf::RectangleShape _sprite;

public:
	explicit Square(const Position& position);
	virtual ~Square() = default;

	virtual void setDefaultColor();
	virtual void setPositionColor();
	virtual void markAsAvaliableMove();
	void setIsOccupied(bool is_occupied);
	void setIsSelected(bool is_selected);
	bool getIsOccupied() const;
	bool getIsSelected() const;
	bool getIsMovePossible() const;
	bool getIsEnPassantPossible() const;

	void draw(sf::RenderWindow* window);
};

