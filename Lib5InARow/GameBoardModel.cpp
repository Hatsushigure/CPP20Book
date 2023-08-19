#include "GameBoardModel.h"

GameBoardModel::GameBoardModel()
{
}

const Piece* GameBoardModel::findPieceAt(int x, int y) const
{
	if (!isInRange(x, y))
		return nullptr;
	return m_board[posToIndex(x, y)];
}

GameBoardModel::PutStatus GameBoardModel::putPiece(const Piece* piece)
{
	if (!isValid(piece->x(), piece->y()))
		return PutStatus::Invalid;
	m_board[posToIndex(piece->x(), piece->y())] = piece;
	return checkPiece(piece);
}

bool GameBoardModel::isInRange(int x, int y) const
{
	if (x < 0 || x >= Width)
		return false;
	if (y < 0 || y >= Width)
		return false;
	return true;
}

GameBoardModel::PutStatus GameBoardModel::checkPiece(const Piece* piece) const
{
	if (countHorizontal(piece) >= 5)
		return GameBoardModel::GameEnd;
	if (countVertical(piece) >= 5)
		return GameBoardModel::GameEnd;
	if (count1To9(piece) >= 5)
		return GameBoardModel::GameEnd;
	if (count2To7(piece) >= 5)
		return GameBoardModel::GameEnd;
	return GameBoardModel::Normal;
}

int GameBoardModel::countHorizontal(const Piece* piece) const
{
	int count {0};
	for (auto i = piece->x();; i--)
	{
		if (!isInRange(i, piece->y()))	//Cannot check places that are out of range
			break;
		auto otherPiece {m_board[posToIndex(i, piece->y())]};
		if (otherPiece == nullptr)	//empty piece
			break;
		if (otherPiece->color() == piece->color())
			count++;
		else
			break;
	}
	count--;
	for (auto i = piece->x();; i++)
	{
		if (!isInRange(i, piece->y()))	//Cannot check places that are out of range
			break;
		auto otherPiece {m_board[posToIndex(i, piece->y())]};
		if (otherPiece == nullptr)	//empty piece
			break;
		if (otherPiece->color() == piece->color())
			count++;
		else
			break;
	}
	return count;
}

int GameBoardModel::countVertical(const Piece* piece) const
{
	int count {0};
	for (auto i = piece->y();; i--)
	{
		if (!isInRange(piece->x(), i))	//Cannot check places that are out of range
			break;
		auto otherPiece {m_board[posToIndex(piece->x(), i)]};
		if (otherPiece == nullptr)	//empty piece
			break;
		if (otherPiece->color() == piece->color())
			count++;
		else
			break;
	}
	count--;
	for (auto i = piece->y();; i++)
	{
		if (!isInRange(piece->x(), i))	//Cannot check places that are out of range
			break;
		auto otherPiece {m_board[posToIndex(piece->x(), i)]};
		if (otherPiece == nullptr)	//empty piece
			break;
		if (otherPiece->color() == piece->color())
			count++;
		else
			break;
	}
	return count;
}

int GameBoardModel::count1To9(const Piece* piece) const
{
	int count {0};
	for (auto i = piece->x(), j = piece->y();; i--, j--)
	{
		if (!isInRange(i, j))	//Cannot check places that are out of range
			break;
		auto otherPiece {m_board[posToIndex(i, j)]};
		if (otherPiece == nullptr)	//empty piece
			break;
		if (otherPiece->color() == piece->color())
			count++;
		else
			break;
	}
	count--;
	for (auto i = piece->x(), j = piece->y();; i++, j++)
	{
		if (!isInRange(i, j))	//Cannot check places that are out of range
			break;
		auto otherPiece {m_board[posToIndex(i, j)]};
		if (otherPiece == nullptr)	//empty piece
			break;
		if (otherPiece->color() == piece->color())
			count++;
		else
			break;
	}
	return count;
}

int GameBoardModel::count2To7(const Piece* piece) const
{
	int count {0};
	for (auto i = piece->x(), j = piece->y();; i++, j--)
	{
		if (!isInRange(i, j))	//Cannot check places that are out of range
			break;
		auto otherPiece {m_board[posToIndex(i, j)]};
		if (otherPiece == nullptr)	//empty piece
			break;
		if (otherPiece->color() == piece->color())
			count++;
		else
			break;
	}
	count--;
	for (auto i = piece->x(), j = piece->y();; i--, j++)
	{
		if (!isInRange(i, j))	//Cannot check places that are out of range
			break;
		auto otherPiece {m_board[posToIndex(i, j)]};
		if (otherPiece == nullptr)	//empty piece
			break;
		if (otherPiece->color() == piece->color())
			count++;
		else
			break;
	}
	return count;
}
