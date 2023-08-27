#include <span>
#include <vector>
#include "../print.h"

auto printContainer(std::span<int> values)
{
	for (auto i : values)
		std::print("{} ", i);
}

int main()
{
	//Span has very low copy cost, just like string_view
	auto vec = std::vector {1, 1, 4, 5, 1, 4};
	printContainer(vec);
}