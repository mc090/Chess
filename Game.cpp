#include "Game.h"

void Game::initializeWindow()
{
	_video_mode.width = 1200;
	_video_mode.height = 800;
	_window = new sf::RenderWindow(sf::VideoMode(_video_mode), "Chess", sf::Style::Titlebar | sf::Style::Close);
	_window->setFramerateLimit(60);
}

void Game::initializePieces()
{
	_pieces.push_back(new Rook("A8", black));
	_pieces.push_back(new Knight("B8", black));
	_pieces.push_back(new Bishop("C8", black));
	_pieces.push_back(new Queen("D8", black));
	_pieces.push_back(new King("E8", black));
	_pieces.push_back(new Bishop("F8", black));
	_pieces.push_back(new Knight("G8", black));
	_pieces.push_back(new Rook("H8", black));
	for (char x = 'A'; x < 'I'; x++) {
		std::string position;
		position.append(1, x).append(1, '7');
		_pieces.push_back(new Pawn(position, black));
	}

	_pieces.push_back(new Rook("A1", white));
	_pieces.push_back(new Knight("B1", white));
	_pieces.push_back(new Bishop("C1", white));
	_pieces.push_back(new Queen("D1", white));
	_pieces.push_back(new King("E1", white));
	_pieces.push_back(new Bishop("F1", white));
	_pieces.push_back(new Knight("G1", white));
	_pieces.push_back(new Rook("H1", white));
	for (char x = 'A'; x < 'I'; x++) {
		std::string position;
		position.append(1, x).append(1, '2');
		_pieces.push_back(new Pawn(position, white));
	}
}



void Game::deletePieces()
{
	for (const auto& piece : _pieces) {
		delete piece;
	}
	_pieces.clear();
}

void Game::updatePiecesPositions()
{
	_board().clear();
	for (const auto piece : _pieces)
	{
		_board()[piece->getPosition()] = piece;
	}

}



bool Game::getWindowIsOpen() const
{
	return _window->isOpen();
}



void Game::pollEvents()
{
	while (_window->pollEvent(_event)) {
		switch (_event.type) {

		case sf::Event::Closed: //jeœli zostanie wciœniety przycisk zamkniecia okna (w prawym górnym rogu) - zamknie sie okno
			_window->close();
			break;

		case sf::Event::KeyPressed: //jeœli zostanie wciœniety przycisk "Escape" - zamknie siê okno
			if (_event.key.code == sf::Keyboard::Escape)
				_window->close();
			break;
		case sf::Event::MouseButtonPressed: //jeœli zostanie wciœniêty lewy przycisk myszy bierka na której jest kursor wykona .move()
			if (_event.mouseButton.button == sf::Mouse::Left)
				if (_mouse_position.x >= 0 and _mouse_position.x < 800 and _mouse_position.y >= 0 and _mouse_position.y < 800) {
					std::string position;
					const char x = _mouse_position.x / 100 + 65;
					const char y = 57 - _mouse_position.y / 100;
					position.append(1, x).append(1, y);

					if (_board().count(position)) {
						_board.setDefaultColors();
						_board[position]->setPositionColor();
						_board()[position]->move();
						_board[_board()[position]->getPosition()]->setPositionColor();
						updatePiecesPositions();
					}
				}
			break;
		}
	}
}

void Game::updateMousePositions()
{
	_mouse_position = _window->mapPixelToCoords(sf::Mouse::getPosition(*_window));
}



void Game::update()
{
	pollEvents();
	updateMousePositions();
}

void Game::render() const
{
	_window->clear(sf::Color(49, 46, 43)); //wyczyszczenie starej klatki oraz nadanie koloru t³a

	_board.draw(_window);
	for (const auto* piece : _pieces) {
		piece->draw(_window);
	}

	_window->display();
}