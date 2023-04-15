#include "Game.h"

int main() {
	Game game;

	while (game.GetWindowIsOpen()) {
		game.Update();
		game.Render();
	}
}