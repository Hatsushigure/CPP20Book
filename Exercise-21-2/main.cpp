#include <regex>
#include <iostream>
#include <string>
#include "../print.h"

int main()
{
	auto reg = std::regex {R"(^(\d{3})-(\d{3})-(\d{4})$)"};
	std::string str {""};
	while (true)
	{
		std::cin >> str;
		if (std::regex_match(str, reg))
			break;
		std::cout << "Invalid!";
	}
	std::smatch ret;
	std::regex_match(str, ret, reg);
	std::print("{}\n{}\n{}\n", stoi(ret[1]), stoi(ret[2]), stoi(ret[3]));
}