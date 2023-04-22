#pragma once

#include "Enum.h"

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
	std::string _position;

public:
	Piece(const team side, std::string position);
	virtual ~Piece() = default;

	std::string getPosition();
	team getSide() const;
	void setPosition(const std::string& position);
	void setToDelete(int& taken_black, int& taken_white);
	bool isToDelete() const;

	virtual std::vector<std::string> getPotentialDestinations() = 0;
	virtual std::vector<std::string> getPathTo(std::string position, const std::string& destination) = 0;

	void draw(sf::RenderWindow* window) const;
};

