import <iostream>;
import <format>;
import <concepts>;
import <string>;

auto contact(auto t1, auto t2) requires ((std::integral<decltype(t1)> || std::floating_point<decltype(t1)>) && (std::integral<decltype(t2)> || std::floating_point<decltype(t2)>))
{
	return std::to_string(t1) + std::to_string(t2);
}

int main()
{
	auto a {1};
	auto b {0.1};
	std::cout << contact(a, b) << '\n';
}