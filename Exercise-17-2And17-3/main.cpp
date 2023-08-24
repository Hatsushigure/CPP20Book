#include <string>
#include <vector>
#include <utility>
#include <ranges>
#include <type_traits>
#include <iostream>
#include <format>

auto sum(auto& rng) requires std::ranges::range<std::decay_t<decltype(rng)>>
{
	auto ret {0};
	for (const auto& i : rng)
		ret += i;
	return ret;
}

auto myCopy(auto& rng) requires std::ranges::range<std::decay_t<decltype(rng)>>
{
	for (const auto& obj : rng)
	{
		std::cout << obj << '\n';
	}
}

struct Person
{
	std::string firstName;
	std::string lastName;
};

auto& operator<<(std::ostream& os, const Person& per)
{
	return os << per.firstName << ' ' << per.lastName;
}

int main()
{
	namespace stdv = std::views;
	auto vec = std::vector<std::pair<Person, int>> {
		std::make_pair(Person {"A", "a"}, 13),
		std::make_pair(Person {"B", "b"}, 25),
		std::make_pair(Person {"C", "c"}, 8),
		std::make_pair(Person {"D", "d"}, 87),
		std::make_pair(Person {"E", "e",}, 36),
		std::make_pair(Person {"F", "f"}, 100),
		std::make_pair(Person {"G", "g"}, 0)
	};
	auto view1 = vec | stdv::values | stdv::filter([](const auto& num) {return ((num >= 12) && (num <= 65)); });
	auto averageAge = static_cast<double>(sum(view1)) / std::distance(begin(view1), end(view1));
	std::cout << std::format("Average age is {:.2f}\n", averageAge);
	
	auto view2 = vec | stdv::keys | stdv::take(4);
	myCopy(view2);

	auto view3 = view2 | stdv::transform([](const Person& per) {return per.lastName; });
	myCopy(view3);
}