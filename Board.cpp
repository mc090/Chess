#include "Board.h"
#include "Pawn.h"


void Board::initializeBoard()
{
	for (char column_char = 'A'; column_char < 'I'; column_char++) {
		for (char row_char = '1'; row_char < '9'; row_char++) {
			Position position(column_char, row_char);
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



Board::Board() : _chosen_piece(nullptr), _en_passant(false)
{
	initializeBoard();
}

Board::~Board()
{
	deleteBoard();
}



Square* Board::operator[](const Position& key)
{
	return _board[key];
}



std::map<Position, Piece*>& Board::getAllPiecesPosition()
{
	return _pieces_position;
}

void Board::setPiecePosition(const Position& position, Piece* piece)
{
	_pieces_position[position] = piece;
}



void Board::hardColorReset() const
{
	for (const auto& square : _board) {
		square.second->setDefaultColor();
	}
}

void Board::softColorReset() const
{
	for (const auto& square : _board) {
		if (square.second->getIsSelected())
		{
			square.second->setDefaultColor();
		}
	}
}


void Board::getMove(const Position& position)
{
	softColorReset();
	if (_pieces_position[position] and !_pieces_position[position]->isToDelete()) {
		_chosen_piece = _pieces_position[position];
		showAvailableMoves(position);
	}
}

void Board::showAvailableMoves(const Position& piece_position)
{
	const std::vector<Position> potential_destinations = _chosen_piece->getPotentialDestinations();
	for (auto& potential_destination : potential_destinations)
	{
		const std::vector<Position> checked_positions = getAvaliableMoves(potential_destination);
		for (auto& position : checked_positions)
		{
			_board[position]->setAvaliableMoveColor();
		}
	}
}

std::vector<Position> Board::getAvaliableMoves(const Position& destination)
{
	std::vector<Position> positions;
	const Position piece_position = _chosen_piece->getPosition();
	const team piece_side = _chosen_piece->getSide();
	const std::vector<Position> path = _chosen_piece->getPathTo(destination);
	if (!dynamic_cast<Pawn*>(_chosen_piece))
	{
		for (auto& position : path)
		{
			if (_pieces_position[position])
			{
				if (_pieces_position[position]->getSide() != piece_side)
				{
					positions.push_back(position);
				}
				return positions;
			}
			else
			{
				positions.push_back(position);
			}
		}
	}
	else
	{
		for (auto& position : path)
		{
			if (position.getColumn() == piece_position.getColumn() + 1
				or position.getColumn() == piece_position.getColumn() - 1)
			{
				if ((_pieces_position[position] and _pieces_position[position]->getSide() != piece_side)
					or enPassant(position))
				{
					positions.push_back(position);
				}
			}
			else
			{
				if (_pieces_position[position])
				{
					return positions;
				}
				positions.push_back(position);
			}
		}
	}
	return positions;
}

void Board::makeMove(const Position& position, int& taken_black, int& taken_white)
{
	hardColorReset();
	const Position old_position = _chosen_piece->getPosition();
	_board[old_position]->setPositionColor();
	if (_pieces_position[position])
	{
		_pieces_position[position]->setToDelete(taken_black, taken_white);
	}
	if (dynamic_cast<Pawn*>(_chosen_piece))
	{
		if (_en_passant)
		{
			int i = _chosen_piece->getSide() ? 1 : -1;
			const Position pawn_position(position.getColumn(), char(position.getRow() + i));
			if (_pieces_position[pawn_position])
			{
				_pieces_position[pawn_position]->setToDelete(taken_black, taken_white);
			}
			_en_passant = false;
		}
		Pawn* pawn = dynamic_cast<Pawn*>(_chosen_piece);
		pawn->setIsStartingPosition(false);
	}
	_chosen_piece->setPosition(position);
	_board[position]->setPositionColor();
}

bool Board::enPassant(const Position& position)
{
	if (_chosen_piece->getPosition().getRow() == '4' or _chosen_piece->getPosition().getRow() == '5')
	{
		const int i = _chosen_piece->getSide() ? -1 : 1;
		const Position starting_pawn_position(position.getColumn(), char(position.getRow() - i));
		const Position pawn_position(position.getColumn(), char(position.getRow() + i));

		if (_board[pawn_position]->getIsEnPassantPossible()
			and _board[starting_pawn_position]->getIsEnPassantPossible()
			and dynamic_cast<Pawn*>(_pieces_position[starting_pawn_position]))
		{
			_en_passant = true;
			return true;
		}
	}
	return false;
}


void Board::draw(sf::RenderWindow* window) const
{
	for (const auto& square : _board) {
		square.second->draw(window);
	}
}
