#include <random>
#include <vector>
#include <algorithm>
#include <execution>

int main()
{
	auto eng = std::default_random_engine {std::random_device{}()};
	auto myRand = std::uniform_int_distribution<> {};
	std::vector<int> vec;
	vec.resize(11451419);
	std::generate(begin(vec), end(vec), [&myRand, &eng] {return myRand(eng); });
	std::sort(std::execution::par_unseq, begin(vec), end(vec));	//very fast!
}