#pragma once

#include "SquareBlack.h"
#include "SquareWhite.h"
#include "Piece.h"
#include "King.h"
#include "Clock.h"

#include <map>


class Board
{
	std::map<Position, Square*> _board;
	std::vector<Piece*> _pieces;
	std::map<Position, Piece*> _pieces_position;
	std::set<Position> _white_avaliable_moves;
	std::set<Position> _black_avaliable_moves;
	King* _black_king;
	King* _white_king;
	Piece* _chosen_piece;
	bool _en_passant;

	// Tworzy obiekty typu Square i zapisje je w _board
	void initializeBoard();

	// Ustawia domyœlny kolor wybranych pól
	void softColorReset() const;

	// Zwraca true, gdy przynajmniej jeden z króli jest atakowany
	bool checkForCheck();

	// Aktualizuje wektor dostêpnych ruchów dla ka¿dej bierki
	void updateAvailableMoves();

	// Zwrata true, gdy wstêpne warunki do przeprowadzenia roszady dla danej pozycji s¹ spe³nione
	bool castling(const Position& position);

	// Usuwa obiekty typu Sqwuare zapisane w _board
	void deleteBoard();

public:

	// Konstruktor
	Board();

	// Destruktor
	~Board();

	// Aktualizuje zbiory zawieraj¹ce pozycje wszystkich atakowanych pól przez bierki danego koloru
	void updateAllAvaliableMoves();

	// Aktualizuje informacje o bierkach w oparciu o ich pozycje
	void update();

	// Aktualizuje pozycje dla ka¿dej bierki
	void updatePiecesPositions();

	// Ustawa wektor dostêpnch bierek
	void setPiecesVector(const std::vector<Piece*>& pieces);

	// Zwraca dostêp do zmiennej _board
	Square* operator[](const Position& key);

	// Zwraca referencje do mapy pozycji bierek
	std::map<Position, Piece*>& getAllPiecesPosition();

	// Wstala now¹ pozycjê dla bierki w mapie
	void setPiecePosition(const Position& position, Piece* piece);

	// Ustala zmienn¹ _chosen_piece
	void setChosenPiece(Piece* piece);

	// Aktualizuje inforamcje o tym czy dane pole jest zajête
	void updateIsOccupied();

	// Zwraca true, gdy król podanego koloru jest atakowany
	bool checkForCheck(team side);

	// Zwraca wektor mo¿liwych ruchów, po których wykonaniu król koloru bierki nie bêdzie atakowany
	std::vector<Position> predictCheck(Piece* piece);

	// Ustala wskaŸnik na króla czarnych
	void setBlackKing(King* king);

	// Ustala wskaŸnik na króla bia³ych
	void setWhiteKing(King* king);

	// Pokazuje dostêpne do wykonania ruchy dla bierki o podanej pozycji 
	void getMove(const Position& position);

	// Ustala mo¿liwe do wykanania ruchy dla podanej bierki
	void setAvailableMoves(Piece* piece);

	// Zwraca wektor ruchów pomiêdzy bierka, a podan¹ pozycj¹
	std::vector<Position> getMovesTowardsDestination(const Position& destination);

	// Wykonuje ruch bierk¹ z aktualnej pozycji na wskazan¹ i zwraca wskaŸnik na t¹ bierkê
	Piece* makeMove(Position& old_position, const Position& new_position,
	                int& taken_black, int& taken_white, bool read_mode);

	// Sprawdza czy jest mo¿liwe wykonanie bicia w przelocie dla podanej pozycji
	bool checkForEnPassant(const Position& position);

	// Ustala mo¿liwoœæ zrobienia bicia w przelocie dla pola o podanej pozycji
	void setEnPassant(const Position& position);

	// Pokazuje szachowniê na ekranie
	void draw(sf::RenderWindow* window) const;

	// Zwraca informacjê o tym czy i w jaki sposób gra zosta³a zakoñczona 
	gameResult isGameFinished(team turn);

	// Sprawdza czy królowie s¹ atakowani
	void isCheck() const;

	// Zwraca pole na którym dostêpne jest bicie w przelocie
	Position enPassantPosition() const;

	// Sprawdza czy dostêpna jest roszada dla króla o podanym kolorze
	void upateCastling(team turn) const;

	// Ustawia domyœlny kolor wszystkich pól
	void hardColorReset() const;
};