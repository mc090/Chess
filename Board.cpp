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

void Board::updatePiecesPositions()
{
	_pieces_position.clear();
	for (const auto& piece : _pieces)
	{
		Position position = piece->getPosition();
		_pieces_position[position] = piece;
	}
	updateMoveMarkers();
}


Board::Board() : _black_king(nullptr), _white_king(nullptr), _chosen_piece(nullptr), _en_passant(false)
{
	initializeBoard();
}

Board::~Board()
{
	deleteBoard();
}

void Board::update()
{
	updatePiecesPositions();
	updateAvailableMoves();
	getAllAvaliableMoves();
}

void Board::setPiecesVector(const std::vector<Piece*>& pieces)
{
	_pieces = pieces;
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

bool Board::checkForCheck()
{
	for (auto position : _black_avaliable_moves)
	{
		if (position.get() == _white_king->getPosition().get())
		{
			return true;
		}
	}
	for (auto position : _white_avaliable_moves)
	{
		if (position.get() == _black_king->getPosition().get())
		{
			return true;
		}
	}
	return false;
}


bool Board::checkForCheck(const team side)
{
	if (side == black)
	{
		for (auto position : _white_avaliable_moves)
		{
			if (position.get() == _black_king->getPosition().get())
			{
				return true;
			}
		}
	}
	else if (side == white)
	{
		for (auto position : _black_avaliable_moves)
		{
			if (position.get() == _white_king->getPosition().get())
			{
				return true;
			}
		}
	}
	return false;
}

std::vector<Position> Board::predictCheck(Piece* piece)
{
	const team side = piece->getSide();
	const Position current_position = piece->getPosition();
	const std::vector<Position> moves = piece->getAvailableMoves();
	std::vector<Position> valid_moves;
	for (auto move : moves)
	{
		if (_pieces_position[move] && _pieces_position[move] != piece)
		{
			Piece* p = _pieces_position[move];
			const team t = p->getSide();
			p->setSide(taken);
			piece->setPosition(move);
			update();
			if (!checkForCheck(side))
			{
				valid_moves.push_back(move);
			}
			p->setSide(t);
		}
		else
		{
			piece->setPosition(move);
			update();
			if (!checkForCheck(side))
			{
				valid_moves.push_back(move);
			}
		}
	}
	piece->setPosition(current_position);
	update();
	return valid_moves;
}

void Board::getAllAvaliableMoves()
{
	std::set<Position> black_moves;
	std::set<Position> white_moves;
	for (const auto piece : _pieces)
	{
		if (piece->getPosition().get() == "H5")
		{
			auto sdsd = piece->getPosition();
		}
		if (piece->getSide() == black)
		{
			for (auto position : piece->getAvailableMoves())
			{
				black_moves.insert(position);
			}
		}
		else if (piece->getSide() == white)
		{
			for (auto position : piece->getAvailableMoves())
			{
				white_moves.insert(position);
			}
		}
	}
	_black_avaliable_moves = black_moves;
	_white_avaliable_moves = white_moves;
}

void Board::updateAvailableMoves()
{
	for (const auto& piece : _pieces)
	{
		if (piece->getSide() != taken)
		{
			setAvailableMoves(piece);
		}
	}
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
	_white_king->isCheck(false);
	_black_king->isCheck(false);
}

void Board::softColorReset() const
{
	for (const auto& square : _board) {
		if (square.second->getIsMovePossible() or square.second->getIsSelected())
		{
			square.second->setDefaultColor();
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
	_board[position]->setIsSelected(true);
	if (_pieces_position[position] and !_pieces_position[position]->isToDelete()) {
		_chosen_piece = _pieces_position[position];
		for (auto& pos : _chosen_piece->getAvailableMoves())
		{
			_board[pos]->markAsAvaliableMove();
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
	if (destination.get() == "E8")
	{
		destination.get();
	}
	if (!dynamic_cast<Pawn*>(_chosen_piece))
	{
		for (auto& position : path)
		{
			// czy na danym polu stoi jakas bierka
			if (_pieces_position[position])
			{
				// czy ta bierka jest innego koloru
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
		//if (_en_passant)
		//{
		//	const int i = _chosen_piece->getSide() ? 1 : -1;
		//	const Position pawn_position(position.getColumn(), char(position.getRow() + i));
		//	if (_pieces_position[pawn_position])
		//	{
		//		_pieces_position[pawn_position]->setToDelete(taken_black, taken_white);
		//	}
		//	_en_passant = false;
		//}
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

void Board::isCheckmateOrStalemate(const team turn)
{
	getAllAvaliableMoves();
	if (turn == black && _black_avaliable_moves.empty() ||
		turn == white && _white_avaliable_moves.empty())
	{
		if (checkForCheck())
		{
			std::cout << "checkmate" << std::endl;
		}
		else
		{
			std::cout << "stalemate" << std::endl;
		}
	}
}

void Board::isCheck() const
{
	for (auto position : _black_avaliable_moves)
	{
		if (position.get() == _white_king->getPosition().get())
		{
			_white_king->isCheck(true);
		}
	}
	for (auto position : _white_avaliable_moves)
	{
		if (position.get() == _black_king->getPosition().get())
		{
			_black_king->isCheck(true);
		}
	}
}
