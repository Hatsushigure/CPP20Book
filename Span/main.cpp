#include <iostream>
#include <format>
#include <span>
#include <vector>

namespace std
{
template <typename... _Args>
void print(format_string<_Args...> _fmt, _Args&&... _args)
{
	cout << format(_fmt, std::forward<_Args>(_args)...);
}

template <typename... _Args>
void println(format_string<_Args...> _fmt, _Args&&... _args)
{
	print(_fmt, std::forward<_Args>(_args)...);
	cout << '\n';
}
}

auto printContainer(std::span<int> values)
{
	for (auto i : values)
		std::print("{} ", i);
}

int main()
{
	//Span has very low copy cost, just like string_view
	auto vec = std::vector {1, 1, 4, 5, 1, 4};
	printContainer(vec);
}