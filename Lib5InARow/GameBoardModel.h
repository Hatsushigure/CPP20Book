#pragma once
#include <array>
#include <tuple>
#include "Piece.h"

class GameBoardModel
{
public:
	enum PutStatus { GameEnd, Normal, Invalid };
	static const int Width {15};
private:
	std::array<const Piece*, Width* Width> m_board {};
public:
	GameBoardModel();
public:
	auto& data() const { return m_board; }
public:
	bool isValid(int x, int y) const { return isInRange(x, y) && (m_board[posToIndex(x, y)] == nullptr); }
	const Piece* findPieceAt(int x, int y) const;
	GameBoardModel::PutStatus putPiece(const Piece* piece);
private:
	bool isInRange(int x, int y) const;
	int posToIndex(int x, int y) const { return y * Width + x; }
	std::tuple<int, int> indexToPos(int index) const { return {index % Width, index / Width}; }
	GameBoardModel::PutStatus checkPiece(const Piece* piece) const;
	int countHorizontal(const Piece* piece) const;
	int countVertical(const Piece* piece) const;
	int count1To9(const Piece* piece) const;	//From Northwest to Southeast
	int count2To7(const Piece* piece) const;	//From NorthEast to Southwest
};

