export module Person;
import <string>;

export struct Person
{
	std::string firstNamr {""};
	std::string lastName {""};

	auto operator<=>(const Person& other) const = default;
};

export Person operator""_p(const char str[], size_t len);