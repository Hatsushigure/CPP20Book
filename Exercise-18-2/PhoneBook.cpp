module PhoneBook;

void PhoneBook::addPhoneNumber(const Person& per, std::initializer_list<std::string>&& numbers)
{
	if (m_data.contains(per))
	{
		m_data[per].insert(end(m_data[per]), begin(numbers), end(numbers));
	}
	else
		m_data.insert(std::pair<Person, std::vector<std::string>> {per, numbers});
}

void PhoneBook::removePhoneNumber(const Person& per, std::string_view number)
{
	if (!m_data.contains(per))
		return;
	auto& numbers = m_data[per];
	auto iter = std::find(begin(numbers), end(numbers), std::string(number));
	if (iter == end(numbers))
		return;
	numbers.erase(iter);
}

const std::vector<std::string>& PhoneBook::numberOf(const Person& per) const
{
	if (!m_data.contains(per))
		return std::vector<std::string> {};
	return m_data.at(per);
}
