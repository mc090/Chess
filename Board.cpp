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



Board::Board() : _black_king(nullptr), _white_king(nullptr), _chosen_piece(nullptr), _en_passant(false)
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

void Board::updateMoveMarkers()
{
	for (const auto& square : _board)
	{
		Position position = square.first;
		if (_pieces_position[position])
		{
			square.second->setIsOccupied(true);
		}
		else
		{
			square.second->setIsOccupied(false);
		}
	}
}

void Board::checkForCheck()
{
	for (auto position : _black_avaliable_moves)
	{
		if (position.get() == _white_king->getPosition().get())
		{
			_board[position]->setCheckColor();
		}
	}
	for (auto position : _white_avaliable_moves)
	{
		if (position.get() == _black_king->getPosition().get())
		{
			_board[position]->setCheckColor();
		}
	}
}

void Board::setBlackAvaliableMoves(const std::set<Position>& moves)
{
	_black_avaliable_moves = moves;
}

void Board::setWhiteAvaliableMoves(const std::set<Position>& moves)
{
	_white_avaliable_moves = moves;
}

void Board::setBlackKing(King* king)
{
	_black_king = king;
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
			square.second->reset();
		}
	}
}

void Board::setWhiteKing(King* king)
{
	_white_king = king;
}

void Board::getMove(const Position& position)
{
	softColorReset();
	if (_pieces_position[position] and !_pieces_position[position]->isToDelete()) {
		_chosen_piece = _pieces_position[position];
		for (auto& pos : _chosen_piece->getAvailableMoves())
		{
			_board[pos]->setAvaliableMoveColor();
		}
	}
}

void Board::setAvailableMoves(Piece* piece)
{
	_chosen_piece = piece;
	const std::vector<Position> potential_destinations = _chosen_piece->getPotentialDestinations();
	std::vector<Position> moves;
	for (auto& potential_destination : potential_destinations)
	{
		const std::vector<Position> checked_positions = getMovesTowardsDestination(potential_destination);
		for (auto& position : checked_positions)
		{
			moves.push_back(position);
		}
	}
	piece->setAvaliableMoves(moves);
}

std::vector<Position> Board::getMovesTowardsDestination(const Position& destination)
{
	std::vector<Position> moves;
	const Position piece_position = _chosen_piece->getPosition();
	const team piece_side = _chosen_piece->getSide();
	const std::vector<Position> path = _chosen_piece->setPathTo(destination);
	if (!dynamic_cast<Pawn*>(_chosen_piece))
	{
		for (auto& position : path)
		{
			if (_pieces_position[position])
			{
				if (_pieces_position[position]->getSide() != piece_side)
				{
					moves.push_back(position);
				}
				return moves;
			}
			else
			{
				moves.push_back(position);
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
					moves.push_back(position);
				}
			}
			else
			{
				if (_pieces_position[position])
				{
					return moves;
				}
				moves.push_back(position);
			}
		}
	}
	return moves;
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
			const int i = _chosen_piece->getSide() ? 1 : -1;
			const Position pawn_position(position.getColumn(), char(position.getRow() + i));
			if (_pieces_position[pawn_position])
			{
				_pieces_position[pawn_position]->setToDelete(taken_black, taken_white);
			}
			_en_passant = false;
		}
		auto* pawn = dynamic_cast<Pawn*>(_chosen_piece);
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
