#include <regex>
#include <string>
#include <iostream>

int main()
{
	auto reg = std::regex {"//.*"};
	std::string str;
	std::getline(std::cin, str, '@');
	auto ret = std::regex_replace(str, reg, "");
	std::cout << ret;
}