#pragma once

class Piece
{
public:
	enum Color { Black, White };
private:
	Piece::Color m_color {Piece::Black};
	int m_x;
	int m_y;
public:
	Piece(const int x, const int y, const Piece::Color color = Piece::Black)
		: m_x {x},
		m_y {y},
		m_color {color}
	{}
public:
	auto x() const { return m_x; }
	auto y() const { return m_y; }
	auto color() const { return m_color; }
};