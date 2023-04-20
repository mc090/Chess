#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum team {
	white = 0,
	black,
};


class Piece
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	const team _side;
	std::string _position;



public:
	Piece(const team side, std::string position);
	virtual ~Piece() = default;

	std::string getPosition();
	team getSide() const;
	void setPosition(const std::string& position);

	virtual std::vector<std::string> getPotentialMoves() = 0;
	virtual std::vector<std::string> getPathTo(std::string position, const std::string& destination) = 0;
	virtual void move(std::vector<std::string> potential_moves) = 0;

	void draw(sf::RenderWindow* window) const;
};

