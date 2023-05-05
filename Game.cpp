#include "Game.h"

void Game::initializeWindow()
{
	sf::Image icon;
	icon.loadFromFile("Textures/icon.png");
	_video_mode.width = 1200;
	_video_mode.height = 800;
	_window = new sf::RenderWindow(sf::VideoMode(_video_mode), "Chess", sf::Style::Titlebar | sf::Style::Close);
	_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	_window->setFramerateLimit(60);
}

void Game::initializePieces()
{
	_pieces.push_back(new Rook(black, "A8"));
	_pieces.push_back(new Knight(black, "B8"));
	_pieces.push_back(new Bishop(black, "C8"));
	_pieces.push_back(new Queen(black, "D8"));
	_pieces.push_back(new King(black, "E8"));
	_pieces.push_back(new Bishop(black, "F8"));
	_pieces.push_back(new Knight(black, "G8"));
	_pieces.push_back(new Rook(black, "H8"));
	for (char column_char = 'A'; column_char < 'I'; column_char++) {
		std::string position;
		position += column_char;
		position += '7';
		_pieces.push_back(new Pawn(black, position));
	}
	_pieces.push_back(new Rook(white, "A1"));
	_pieces.push_back(new Knight(white, "B1"));
	_pieces.push_back(new Bishop(white, "C1"));
	_pieces.push_back(new Queen(white, "D1"));
	_pieces.push_back(new King(white, "E1"));
	_pieces.push_back(new Bishop(white, "F1"));
	_pieces.push_back(new Knight(white, "G1"));
	_pieces.push_back(new Rook(white, "H1"));
	for (char column_char = 'A'; column_char < 'I'; column_char++) {
		std::string position;
		position += column_char;
		position += '2';
		_pieces.push_back(new Pawn(white, position));
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
	_board.getAllPiecesPosition().clear();
	for (const auto& piece : _pieces)
	{
		Position position = piece->getPosition();
		_board.setPiecePosition(position, piece);
	}
	_board.updateMoveMarkers();
}

Position Game::getClickedPiecePosition() const
{
	char column_char = _mouse_position.x / 100 + 65;
	char row_char = 57 - _mouse_position.y / 100;
	const Position position(column_char, row_char);
	return position;
}


Game::Game() :_window(nullptr), _event(), _taken_black(0), _taken_white(0)
{
	initializeWindow();
	initializePieces();
	updatePiecesPositions();
}

Game::~Game()
{
	delete _window;
	deletePieces();
};



bool Game::getWindowIsOpen() const
{
	return _window->isOpen();
}



void Game::pollEvents()
{
	while (_window->pollEvent(_event)) {
		switch (_event.type) {

		case sf::Event::Closed:
			_window->close();
			break;

		case sf::Event::KeyPressed:
			if (_event.key.code == sf::Keyboard::Escape)
				_window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (_event.mouseButton.button == sf::Mouse::Left)
				if (_mouse_position.x >= 0 and _mouse_position.x < 800 and _mouse_position.y >= 0 and _mouse_position.y < 800) {
					Position position = getClickedPiecePosition();
					if (!_board[position]->getIsSelected())
					{
						_board.getMove(position);
					}
					else
					{
						_board.makeMove(position, _taken_black, _taken_white);
					}
					updatePiecesPositions();
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
	_window->clear(sf::Color(49, 46, 43));

	_board.draw(_window);
	for (auto piece : _pieces) {
		piece->draw(_window);
	}

	_window->display();
}