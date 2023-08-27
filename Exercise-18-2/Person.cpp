module Person;

Person operator""_p(const char str[], size_t len)
{
	auto tmpStr = std::string {str, len};
	auto ind = tmpStr.find_last_of(' ');

	if (ind == 0)
		throw std::exception {"Your full name cannot begin with space"};

	auto firstName = tmpStr.substr(0, ind);
	auto lastName = std::string {};
	if (ind != tmpStr.size())
		lastName = tmpStr.substr(ind + 1);
	return Person {firstName, lastName};
}