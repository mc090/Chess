#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Square
{
	std::string _position;
	bool _is_selected;

	void initializeSprite();

protected:
	sf::RectangleShape _sprite;

public:
	explicit Square(std::string position);
	virtual ~Square() = default;

	virtual void setDefaultColor();
	virtual void setPositionColor() = 0;
	virtual void setPotenitalMoveColor();
	bool getIsSelected() const;

	void draw(sf::RenderWindow* window) const;
};

