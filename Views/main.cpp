#include <array>
#include <ranges>
#include <iostream>
#include <format>
#include <concepts>

template <typename Rng> requires std::ranges::range<Rng>
inline void printRng(Rng& rng)
{
	for (const auto& var : rng)
		std::cout << std::format("{} ", var);
	std::cout << "\n";
}

inline bool isEven(auto num) requires std::integral<decltype(num)>
{
	return num % 2 == 0;
}

int main()
{
	namespace stdv = std::views;
	auto arr {std::array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

	auto ret1 {arr | stdv::all};
	std::cout << "Everything as before:\n";
	printRng(ret1);

	auto ret2 {arr | stdv::filter(isEven<int>)};
	std::cout << "\nOnly even:\n";
	printRng(ret2);

	auto ret3 {arr | stdv::take(3)};
	std::cout << "\nFirst 3 elements:\n";
	printRng(ret3);

	auto ret4 {arr | stdv::drop(3)};
	std::cout << "\nEverything except the first 3 elements:\n";
	printRng(ret4);

	auto arr2 {std::array
	{
		std::tuple {1, 'A', "¦Á"},
		std::tuple {2, 'B', "¦Â"},
		std::tuple {3, 'C', "¦Ã"},
		std::tuple {4, 'D', "¦Ä"},
		std::tuple {5, 'E', "¦Å"},
	}};
	auto ret5 {arr2 | stdv::elements<0>};
	auto ret6 {arr2 | stdv::elements<1>};
	auto ret7 {arr2 | stdv::elements<2>};
	std::cout << "\nExtract element at certain index:\n";
	printRng(ret5);
	printRng(ret6);
	printRng(ret7);

	auto ret8 {arr | stdv::transform([](const int& var) {return var * 10; })};
	std::cout << "\nEverything * 10 (not changing the original array):\n";
	printRng(ret8);
	printRng(arr);

	auto ret9 {arr | stdv::filter(isEven<int>) | stdv::transform([](int& val) {return val *= 10; })};
	std::cout << "\nChanges the original value using views:\n";
	printRng(ret9);
	printRng(arr);
}