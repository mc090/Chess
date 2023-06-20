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

void Board::setChosenPiece(Piece* piece)
{
	_chosen_piece = piece;
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

bool Board::castling(const Position& position)
{
	const int i = position.getColumn() == 'C' ? -2 : 1;
	const Position rook_position(char(position.getColumn() + i), position.getRow());
	if (_pieces_position[rook_position])
	{
		const Piece* rook = _pieces_position[rook_position];
		if (!rook->getIsStartingPosition())
		{
			return false;
		}
		const int j = position.getColumn() == 'C' ? 1 : -1;
		const Position new_rook_position(char(position.getColumn() + j), position.getRow());
		if (_pieces_position[new_rook_position] || _pieces_position[position])
		{
			return false;
		}
		return true;
	}
	return false;
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
		for (auto& move : _chosen_piece->getAvailableMoves())
		{
			_board[move]->markAsAvaliableMove();
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
			if (dynamic_cast<King*>(_chosen_piece) && _chosen_piece->getIsStartingPosition() &&
				(position.get() == "C1" || position.get() == "G1" || position.get() == "C8" || position.get() == "G8"))
			{
				if (castling(position))
				{
					moves.push_back(position);
				}
			}
			else
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
	}
	else
	{
		for (auto& position : path)
		{
			if (position.getColumn() == piece_position.getColumn() + 1
				or position.getColumn() == piece_position.getColumn() - 1)
			{
				if ((_pieces_position[position] && _pieces_position[position]->getSide() != piece_side) ||
					checkForEnPassant(position))
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

Piece* Board::makeMove(const Position& position, int& taken_black, int& taken_white)
{
	const Position en_passant = enPassantPosition();
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
			if (position.get() == en_passant.get() && _pieces_position[pawn_position])
			{
				_pieces_position[pawn_position]->setToDelete(taken_black, taken_white);
			}
			_en_passant = false;
		}
		_chosen_piece->setStartingPositionFalse();
		_chosen_piece->setPosition(position);
		_board[position]->setPositionColor();
		setEnPassant(old_position);
	}
	else
	{
		if (dynamic_cast<King*>(_chosen_piece) && _chosen_piece->getIsStartingPosition() &&
			(position.get() == "C1" || position.get() == "G1" || position.get() == "C8" || position.get() == "G8"))
		{
			const int i = position.getColumn() == 'C' ? -2 : 1;
			const int j = position.getColumn() == 'C' ? 1 : -1;
			const Position rook_position(char(position.getColumn() + i), position.getRow());
			const Position new_rook_position(char(position.getColumn() + j), position.getRow());
			Piece* rook = _pieces_position[rook_position];
			rook->setStartingPositionFalse();
			rook->setPosition(new_rook_position);
		}
		_chosen_piece->setStartingPositionFalse();
		_chosen_piece->setPosition(position);
		_board[position]->setPositionColor();
	}
	return _chosen_piece;
}

bool Board::checkForEnPassant(const Position& position)
{
	if (_chosen_piece->getPosition().getRow() == '4' or _chosen_piece->getPosition().getRow() == '5')
	{
		const int i = _chosen_piece->getSide() ? -1 : 1;

		if (_board[position]->getIsEnPassantPossible())
		{
			_en_passant = true;
			return true;
		}
	}
	return false;
}

void Board::setEnPassant(const Position& old_position)
{
	if (old_position.getRow() == '2' && _chosen_piece->getPosition().getRow() == '4' ||
		old_position.getRow() == '7' && _chosen_piece->getPosition().getRow() == '5')
	{
		const int i = _chosen_piece->getSide() ? -1 : 1;
		const Position en_passant(old_position.getColumn(), char(old_position.getRow() + i));
		_board[en_passant]->setIsEnPassantPossible(true);
	}
}


void Board::draw(sf::RenderWindow* window) const
{
	for (const auto& square : _board) {
		square.second->draw(window);
	}
}

gameResult Board::isCheckmateOrStalemate(const team turn)
{
	getAllAvaliableMoves();
	if (turn == black && _black_avaliable_moves.empty() ||
		turn == white && _white_avaliable_moves.empty())
	{
		if (checkForCheck())
		{
			return turn ? white_won : black_won;
		}
		else
		{
			return tie;
		}
	}
	return nothing;
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

Position Board::enPassantPosition() const
{
	for (const auto& square : _board) {
		if (square.second->getIsEnPassantPossible())
		{
			return square.first;
		}
	}
	return Position("00");
}

void Board::upateCastling(const team turn)
{
	//3. nie ma szacha
	//4. pole przez ktore przejdzie krul nie jest atakowane
	//5. po roszadzie krol nie bedzie pod szachem
	King* king = turn ? _black_king : _white_king;
	if (king->getIsStartingPosition())
	{
		const std::vector<Position> king_moves = king->getAvailableMoves();
		std::vector<Position> valid_moves;
		for (auto king_move : king_moves)
		{
			if (king_move.get() == "C1" || king_move.get() == "G1" || king_move.get() == "C8" || king_move.get() == "G8")
			{
				const int j = king_move.getColumn() == 'C' ? 1 : -1;
				const Position new_rook_position(char(king_move.getColumn() + j), king_move.getRow());
				bool temp = true;
				for (auto opponents_move : (turn ? _white_avaliable_moves : _black_avaliable_moves))
				{
					if (opponents_move.get() == king->getPosition().get() ||
						opponents_move.get() == new_rook_position.get() ||
						opponents_move.get() == king_move.get())
					{
						temp = false;
					}
				}
				if (temp)
				{
					valid_moves.push_back(king_move);
				}
			}
			else {
				valid_moves.push_back(king_move);
			}
		}
		king->setAvaliableMoves(valid_moves);
	}
}
