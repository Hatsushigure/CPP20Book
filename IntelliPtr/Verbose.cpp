#include "Verbose.h"
#include <iostream>
#include <format>

int Verbose::s_total {0};

Verbose::Verbose()
{
	m_index = s_total;
	s_total++;
	std::cout << std::format("Object #{} is constructed!\n", m_index);
}

Verbose::~Verbose()
{
	std::cout << std::format("Object #{} is destroyed!\n", m_index);
}
