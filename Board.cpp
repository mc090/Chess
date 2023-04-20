#include "Board.h"


void Board::initializeBoard()
{
	for (char column_char = 'A'; column_char < 'I'; column_char++) {
		for (char row_char = '1'; row_char < '9'; row_char++) {
			std::string position;
			position += column_char;
			position += row_char;
			if (int(column_char + row_char) % 2) {
				_board[position] = new SquareBlack(position);
			}
			else {
				_board[position] = new SquareWhite(position);
			}
		}
	}
}



void Board::deleteBoard()
{
	for (const auto& square : _board) {
		delete square.second;
	}
	_board.clear();
	_pieces_position.clear();
}



Board::Board()
{
	initializeBoard();
}

Board::~Board()
{
	deleteBoard();
}



Square* Board::operator[](const std::string& key)
{
	return _board[key];
}



std::map<std::string, Piece*>& Board::getAllPiecesPosition()
{
	return _pieces_position;
}

void Board::setPiecePosition(const std::string& position, Piece* piece)
{
	_pieces_position[position] = piece;
}



void Board::setDefaultColors() const
{
	for (const auto& square : _board) {
		square.second->setDefaultColor();
	}
}

void Board::move(const std::string& position)
{
	if (_pieces_position[position]) {
		setDefaultColors();
		_board[position]->setPositionColor();

		showAvailableMoves(position);

		const std::string new_position = _pieces_position[position]->getPosition();
		_board[new_position]->setPositionColor();
	}
}


std::vector<std::string> Board::availableSquares(const std::string& piece_position)
{
	std::vector<std::string> positions;
	Piece* piece = _pieces_position[piece_position];
	const std::vector<std::string> potential_destinations = piece->getPotentialMoves();
	for (const auto& potential_destination : potential_destinations)
	{
		const std::vector<std::string> checked_positions = isMovePossible(potential_destination, piece);
		for (const auto& position : checked_positions)
		{
			positions.push_back(position);
		}
	}
	return positions;
}

std::vector<std::string> Board::isMovePossible(const std::string& destination, Piece* piece)
{
	std::vector<std::string> positions;
	const std::vector<std::string> path = piece->getPathTo(piece->getPosition(), destination);
	for (auto& position : path)
	{
		if (_pieces_position[position])
		{
			if (_pieces_position[position]->getSide() == piece->getSide())
			{
				return positions;
			}
			positions.push_back(position);
			return positions;
		}
		else
		{
			positions.push_back(position);
		}
	}
	return positions;
}

void Board::showAvailableMoves(const std::string& piece_position)
{
	const std::vector<std::string> available_moves = availableSquares(piece_position);
	for(const auto& position:available_moves)
	{
		_board[position]->setPotenitalMoveColor();
	}
}



void Board::draw(sf::RenderWindow* window) const
{
	for (const auto& square : _board) {
		square.second->draw(window);
	}
}
