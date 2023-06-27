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
	auto* black_king = new King(black, "E8");
	auto* white_king = new King(white, "E1");
	_pieces.push_back(new Rook(black, "A8"));
	_pieces.push_back(new Knight(black, "B8"));
	_pieces.push_back(new Bishop(black, "C8"));
	_pieces.push_back(new Queen(black, "D8"));
	_pieces.push_back(black_king);
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
	_pieces.push_back(white_king);
	_pieces.push_back(new Bishop(white, "F1"));
	_pieces.push_back(new Knight(white, "G1"));
	_pieces.push_back(new Rook(white, "H1"));
	for (char column_char = 'A'; column_char < 'I'; column_char++) {
		std::string position;
		position += column_char;
		position += '2';
		_pieces.push_back(new Pawn(white, position));
	}
	_board.setBlackKing(black_king);
	_board.setWhiteKing(white_king);
}

void Game::initializeGameSaving()
{
	_moves_made = new std::vector<std::pair<std::string, std::string>>;
	std::thread save_game([&]() {	_file_manager.saveGameToFile(_moves_made); });
	save_game.detach();
}

void Game::deletePieces()
{
	for (const auto& piece : _pieces) {
		delete piece;
	}
	_pieces.clear();
}

void Game::predictCheck()
{
	std::map<Piece*, std::vector<Position>> valid_moves;
	for (auto* piece : _pieces)
	{
		if (piece->getSide() == _turn)
		{
			valid_moves[piece] = _board.predictCheck(piece);
		}
	}
	for (auto move : valid_moves)
	{
		move.first->setAvaliableMoves(move.second);
	}
}

Position Game::getClickedPosition() const
{
	char column_char = _mouse_position.x / 100 + 65;
	char row_char = 57 - _mouse_position.y / 100;
	const Position position(column_char, row_char);
	return position;
}


Game::Game() :_window(nullptr), _event(), _taken_black(0), _taken_white(0), _turn(white),
_selected_piece_position("SS"), _pawn_promotion(nullptr), _chosen_piece(nullptr), _is_pawn_promotion(false),
_game_result(nothing), _victory_screen(nullptr), _is_game_started(false)
{
	initializeWindow();
	initializeGameSaving();
	initializePieces();
	_board.setPiecesVector(_pieces);
	_board.updatePiecesPositions();
	updateAvailableMoves();
	_black_clock = new Clock(sf::Vector2f(915.f, 315.f));
	_white_clock = new Clock(sf::Vector2f(915.f, 415.f));
}

Game::~Game()
{
	delete _window;
	deletePieces();
	_file_manager.closeGame();
	_file_manager.save();
};



bool Game::getWindowIsOpen() const
{
	return _window->isOpen();
}

void Game::updateAvailableMoves()
{
	for (const auto& piece : _pieces)
	{
		if (piece->getSide() != taken)
		{
			_board.setAvailableMoves(piece);
		}
	}
}

void Game::pollEvents()
{
	while (_window->pollEvent(_event)) {
		switch (_event.type) {

		// Zamkniêcie okna
		case sf::Event::Closed:
			saveTime();
			_window->close();
			break;

		// Naciœniêcie klawisza escape - zamkniêcie okna
		case sf::Event::KeyPressed:
			if (_event.key.code == sf::Keyboard::Escape)
			{
				saveTime();
				_window->close();
			}
			break;

		// Wykonywanie akcji po klikniêciu myszk¹
		case sf::Event::MouseButtonPressed:
			if (_event.mouseButton.button == sf::Mouse::Left)
			{
				if (!_game_result)
				{
					if (!_is_pawn_promotion)
					{
						if (!_is_game_started &&
							_file_manager.isLastGamePathAvaliable() &&
							_mouse_position.x >= 875 && _mouse_position.x < 1125 &&
							_mouse_position.y >= 700 && _mouse_position.y < 750) {
							*_moves_made = _file_manager.loadGameFromFile();
							for (auto it = _moves_made->begin() + 1; it < _moves_made->end(); ++it)
							{
								Position old_position((*it).first);
								Position new_position((*it).second);
								_board.makeMove(old_position, new_position, _taken_black, _taken_white, true);
								_board.update();
								_turn = _turn ? white : black;
							}
							_white_clock->setTime(std::stoi(_moves_made->at(0).first));
							_black_clock->setTime(std::stoi(_moves_made->at(0).second));
							_is_game_started = true;
							if (dynamic_cast<Pawn*>(_chosen_piece) &&
								(_chosen_piece->getPosition().getRow() == '1' || _chosen_piece->getPosition().getRow() == '8'))
							{
								_pawn_promotion = new PawnPromotion(_turn);
								_is_pawn_promotion = true;
								break;
							}
							_board.update();
							_turn ? _black_clock->start() : _white_clock->start();
							_turn ? _white_clock->pause() : _black_clock->pause();
							predictCheck();
							_board.upateCastling(_turn);
							_selected_piece_position.set("TS");
							_board.isCheck();
							const gameResult is_game_finished = _board.isGameFinished(_turn);
							if (is_game_finished)
							{
								_victory_screen = new VictoryScreen(is_game_finished);
								_game_result = is_game_finished;
								_black_clock->restart();
								_white_clock->restart();
							}
						}
						if (_mouse_position.x >= 0 && _mouse_position.x < 800 &&
							_mouse_position.y >= 0 && _mouse_position.y < 800) {
							Position new_position = getClickedPosition();
							if (!_board[new_position]->getIsMovePossible())
							{
								if (_board[new_position]->getIsOccupied() && _board.getAllPiecesPosition()[new_position]->getSide() == _turn)
								{
									_selected_piece_position = new_position;
									_board.getMove(_selected_piece_position);
								}
							}
							else
							{
								if (_selected_piece_position.get() != "TS")
								{
									Position old_position("00");
									_chosen_piece = _board.makeMove(old_position, new_position, _taken_black, _taken_white, false);
									if (!_is_game_started)
									{
										_black_clock->restart();
										_white_clock->restart();
										_is_game_started = true;
									}
									saveMove(old_position, new_position);
									if (dynamic_cast<Pawn*>(_chosen_piece) &&
										(_chosen_piece->getPosition().getRow() == '1' || _chosen_piece->getPosition().getRow() == '8'))
									{
										_pawn_promotion = new PawnPromotion(_turn);
										_is_pawn_promotion = true;
										break;
									}
									_board.update();
									_turn = _turn ? white : black;
									_turn ? _black_clock->start() : _white_clock->start();
									_turn ? _white_clock->pause() : _black_clock->pause();
									predictCheck();
									_board.upateCastling(_turn);
									_selected_piece_position.set("TS");
									_board.isCheck();
									const gameResult is_game_finished = _board.isGameFinished(_turn);
									if (is_game_finished)
									{
										_victory_screen = new VictoryScreen(is_game_finished);
										_game_result = is_game_finished;
										_black_clock->restart();
										_white_clock->restart();
									}
								}
							}
						}

					}
					else
					{
						if (_mouse_position.x > 150.f && _mouse_position.x < 650.f &&
							_mouse_position.y > 337.5 && _mouse_position.y < 462.5) {
							promotePawn();
							_is_pawn_promotion = false;
							delete _pawn_promotion;
							_board.update();
							_turn = _turn ? white : black;
							predictCheck();
							_board.upateCastling(_turn);
							_selected_piece_position.set("TS");
							_board.isCheck();
							const gameResult is_game_finished = _board.isGameFinished(_turn);
							if (is_game_finished)
							{
								_victory_screen = new VictoryScreen(is_game_finished);
								_game_result = is_game_finished;
								_black_clock->restart();
								_white_clock->restart();
							}
						}
					}
				}
				else
				{
					resetGameSaving();
					deletePieces();
					initializePieces();
					_board.setPiecesVector(_pieces);
					_board.updatePiecesPositions();
					updateAvailableMoves();
					_board.hardColorReset();
					_turn = white;
					_is_game_started = false;
					_taken_black = 0;
					_taken_white = 0;
					_game_result = nothing;
					delete _victory_screen;
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
	const gameResult is_game_finished = isGameFinishedByTime();
	if (is_game_finished)
	{
		_victory_screen = new VictoryScreen(is_game_finished);
		_game_result = is_game_finished;
		_black_clock->restart();
		_white_clock->restart();
	}
}

void Game::render() const
{
	_window->clear(sf::Color(49, 46, 43));

	_board.draw(_window);
	for (const auto piece : _pieces) {
		piece->draw(_window);
	}
	if (_is_pawn_promotion)
	{
		_pawn_promotion->draw(_window);
	}
	if (_game_result)
	{
		_victory_screen->draw(_window);
	}
	if (!_is_game_started && _file_manager.isLastGamePathAvaliable())
	{
		_file_manager.drawLoadingButton(_window);
	}
	_black_clock->draw(_window);
	_white_clock->draw(_window);

	_window->display();
}

void Game::promotePawn()
{
	Piece* new_piece;
	if (_mouse_position.x < 275.f)
	{
		new_piece = new Queen(_chosen_piece->getSide(), _chosen_piece->getPosition().get());
	}
	else if (_mouse_position.x < 400.f)
	{
		new_piece = new Rook(_chosen_piece->getSide(), _chosen_piece->getPosition().get());
	}
	else if (_mouse_position.x < 525.f)
	{
		new_piece = new Knight(_chosen_piece->getSide(), _chosen_piece->getPosition().get());
	}
	else
	{
		new_piece = new Bishop(_chosen_piece->getSide(), _chosen_piece->getPosition().get());
	}

	auto lambda = [&](const Piece* piece) { return piece->getPosition().get() == _chosen_piece->getPosition().get(); };
	const auto piece = std::ranges::find_if(_pieces.begin(), _pieces.end(), lambda);
	delete* piece;
	_pieces.erase(piece);

	_pieces.push_back(new_piece);
	_board.setPiecesVector(_pieces);
	_board.setChosenPiece(new_piece);
}

gameResult Game::isGameFinishedByTime()
{
	if (_is_game_started)
	{
		if (_white_clock->getRemainigTime() <= 0)
		{
			_is_game_started = false;
			return black_won;
		}
		if (_black_clock->getRemainigTime() <= 0)
		{
			_is_game_started = false;
			return white_won;
		}
	}
	return nothing;
}

void Game::saveMove(const Position& old_position, const Position& new_position)
{
	saveTime();
	_moves_made->push_back({ old_position.get(), new_position.get() });
	_file_manager.save();
}

void Game::saveTime()
{
	if (_moves_made->empty())
	{
		_moves_made->push_back({
			std::to_string(_white_clock->getRemainigTime()),
			std::to_string(_black_clock->getRemainigTime()) });
	}
	else
	{
		_moves_made->at(0) = {
			std::to_string(_white_clock->getRemainigTime()),
			std::to_string(_black_clock->getRemainigTime()) };
	}
	_file_manager.save();
}

void Game::resetGameSaving()
{
	_moves_made->clear();
	_file_manager.incGameNumber();
}