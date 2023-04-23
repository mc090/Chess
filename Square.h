#pragma once

#include "Position.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Square
{
	Position _position;
	bool _is_selected;
	bool _is_en_passant_possible;

	void initializeSprite();

protected:
	sf::RectangleShape _sprite;

public:
	explicit Square(const Position& position);
	virtual ~Square() = default;

	virtual void setDefaultColor();
	virtual void setPositionColor();
	virtual void setAvaliableMoveColor();
	bool getIsSelected() const;
	bool getIsEnPassantPossible() const;

	void draw(sf::RenderWindow* window) const;
};

