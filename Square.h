#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Square
{
	std::string _position;

	void initializeSprite();

protected:
	sf::RectangleShape _sprite;

public:
	explicit Square(std::string position) :_position(std::move(position)) {
		initializeSprite();
	}
	virtual ~Square() = default;

	virtual void setDefaultColor() = 0;
	virtual void setPositionColor() = 0;
	virtual void setPotenitalMoveColor() = 0;

	void draw(sf::RenderWindow* window) const;
};

