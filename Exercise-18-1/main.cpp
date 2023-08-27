#include "../print.h"
#include <vector>

auto main() -> int
{
	auto vec1 = std::vector {2, 5};
	auto iter = begin(vec1);
	++iter;
	vec1.insert(iter, {3, 4});
	auto vec2 = std::vector {0, 1};
	vec1.insert(begin(vec1), begin(vec2), end(vec2));
	auto vec3 = std::vector<int> {};
	for (auto iter = crbegin(vec1); iter != crend(vec1); iter++)
		vec3.push_back(*iter);
	for (auto val : vec3)
		std::print("{} ", val);
	std::print("\n");
}