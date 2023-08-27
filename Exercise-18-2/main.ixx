#include "../print.h"
import Person;
import PhoneBook;

auto main() -> int
{
	auto pb = PhoneBook {};

	pb.addPhoneNumber("A a"_p, {"111111111111", "222222222222", "3333333333"});
	auto& lst1 = pb.numberOf("A a"_p);
	for (const auto& str : lst1)
		std::println("{}", str);
	std::print("\n");

	pb.addPhoneNumber("A a"_p, {"444444444444"});
	for (const auto& str : lst1)
		std::println("{}", str);
	std::print("\n");

	pb.removePhoneNumber("A a"_p, "222222222222");
	for (const auto& str : lst1)
		std::println("{}", str);
	std::print("\n");

	pb.addPhoneNumber("A a"_p, {"114514", "1919810"});
	for (const auto& str : lst1)
		std::println("{}", str);
	std::print("\n");
}