#include <iostream>
#include <format>
#include <vector>

using std::cin, std::format, std::cout, std::vector;

int main()
{
	double ret {-1};
	vector<double> vec {};
	do
	{
		cin >> ret;
		vec.push_back(ret);
	} while (ret != 0);
	vec.pop_back();
	for (auto n : vec)
		cout << format("|{:^20e}|{:^20.2f}|\n", n, n);
}