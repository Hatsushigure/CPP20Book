#include <vector>
#include <vector>
#include <format>
#include <iostream>

int main()
{
	auto vec {std::vector {1, 1, 4, 5, 1, 4}};

	//member
	auto beginIter1 {vec.begin()};
	auto endIter1 {vec.end()};
	//global
	auto beginIter2 {begin(vec)};
	auto endIter2 {end(vec)};

	std::cout << std::format("diatance between beginIter1 and endIter1 is {}\n", distance(beginIter1, endIter1));
	std::cout << std::format("diatance between beginIter2 and endIter2 is {}\n", distance(beginIter2, endIter2));
	std::cout << std::format("diatance between beginIter1 and beginIter2 is {}\n", distance(beginIter1, beginIter2));
}