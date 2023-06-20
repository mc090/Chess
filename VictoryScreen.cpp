#include "VictoryScreen.h"

VictoryScreen::VictoryScreen(const gameResult& game_result)
{
	switch (game_result) {
	case black_won:
		_texture.loadFromFile("Textures/BlackVictory.png");
		break;
	case white_won:
		_texture.loadFromFile("Textures/WhiteVictory.png");
		break;
	case tie:
		_texture.loadFromFile("Textures/Draw.png");
		break;
	}
	_sprite.setTexture(_texture);
	_sprite.setPosition(275.f, 275.f);
}

void VictoryScreen::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}
