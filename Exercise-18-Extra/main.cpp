#include <iostream>

template <typename... Args>
double average(Args... args)
{
	double sum {0};
	((sum += args), ...);
	return sum / sizeof...(args);
}

int main()
{
	std::cout << average(1, 1, 4, 5, 1, 4);
}