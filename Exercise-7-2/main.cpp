#include <iostream>
#include <array>

constexpr size_t numberOfElements {10};

int main()
{
	std::array<int, numberOfElements> values;
	for (auto i {0}; i < values.size(); i++)
		values[i] = i;
	values.back() = 99;
	for (auto i : values)
		std::cout << i << ' ';
}