module;
import Enum;
#include <SFML/Graphics.hpp>
export module VictoryScreen;

export class VictoryScreen
{
	sf::Texture _texture;
	sf::Sprite _sprite;

public:

	// Konstruktor
	explicit VictoryScreen(const gameResult& game_result);

	// Pokazuje pole informujące o wygranej gracza lub remisie na ekranie
	void draw(sf::RenderWindow* window) const;
};