#include <iostream>
#include <format>

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
