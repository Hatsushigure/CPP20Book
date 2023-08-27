#include <functional>
#include <iostream>
#include <type_traits>

class Processor
{
private:
	std::function<int(int)> m_callback;
public:
	Processor(std::function<int(int)> callback) : m_callback {callback} {}
public:
	int operator()(int arg)
	{
		return m_callback(std::forward<int>(arg));
	}
};

int main()
{
	auto obj1 = Processor {[](int arg) {return arg + 1; }};
	std::cout << obj1(1);
}