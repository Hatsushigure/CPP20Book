#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <format>
namespace stdr = std::ranges;

class Person
{
private:
	std::string m_firstName {""};
	std::string m_lastName {""};
public:
	Person(const std::string& m_firstName, const std::string& m_lastName)
		: m_firstName(m_firstName), m_lastName(m_lastName)
	{
	}
public:
	auto firstName() const { return m_firstName; }
	auto lastName() const { return m_lastName; }
};

auto main() -> int
{
	auto arr {std::array {1, 1, 4, 5, 1, 4}};
	auto arr2 {arr};
	stdr::sort(arr);
	std::sort(begin(arr2), end(arr2));
	for (auto i : arr)
		std::cout << std::format("{}\n", i);
	for (auto i : arr2)
		std::cout << std::format("{}\n", i);

	//Projection, unique to ranges
	auto arr3 {std::array {Person {"John", "Brown"}, Person {"Chris", "White"}}};
	stdr::sort(arr3, {}, &Person::firstName);
	for (const auto& per : arr3)
		std::cout << std::format("{}\n", per.firstName());
}