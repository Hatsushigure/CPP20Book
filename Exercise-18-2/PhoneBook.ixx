export module PhoneBook;
import <vector>;
import <map>;
import <string>;
import <initializer_list>;
import<string_view>;
import Person;

export class PhoneBook
{
private:
	std::map<Person, std::vector<std::string>> m_data;
public:
	void addPhoneNumber(const Person& per, std::initializer_list<std::string>&& numbers);
	void removePhoneNumber(const Person& per, std::string_view number);
	const std::vector<std::string>& numberOf(const Person& per) const;
};
