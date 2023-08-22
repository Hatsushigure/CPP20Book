#include <ranges>
#include <string>
#include <iostream>

int main()
{
	namespace stdv = std::views;
	namespace stdr = std::ranges;
	auto myView = 
		stdv::iota(10)
		| stdv::take_while([](const auto& num) {return num <= 100; })
		| stdv::transform([](const auto& num) {return num * num; })
		| stdv::filter([](const auto& num) {return num % 5 != 0; })
		| stdv::transform([](const auto& num) {return std::to_string(num); });

	for (const auto& str : myView)
		std::cout << str << ' ';
}