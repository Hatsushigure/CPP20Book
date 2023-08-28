#include <vector>
#include <algorithm>
#include <execution>
#include "../print.h"

int main()
{
	namespace stdr = std::ranges;
	auto vec = std::vector {1, 1, 4, 5, 1, 4};
	stdr::sort(vec);	//Do not support parallel sorting
	for (auto i : vec)
		std::print("{} ", i);
}