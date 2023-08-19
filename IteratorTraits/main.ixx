import std;

auto main() -> int
{
	auto vec {std::vector {1, 1, 4, 5, 1, 4}};
	using ValType = std::iterator_traits<decltype(vec.begin())>::value_type;	//should be int
	using DiffType = std::iterator_traits<decltype(vec.begin())>::difference_type;	//long long since te distance between pointers uses long long
	using PtrType = std::iterator_traits<decltype(vec.begin())>::pointer;	//int*
	using RefType = std::iterator_traits<decltype(vec.begin())>::reference;	//int&
	std::println("Type of ValType {} int.", std::is_same<ValType, int>::value ? "is" : "is not");
	std::println("Type of DiffType {} long long.", std::is_same<DiffType, long long>::value ? "is" : "is not");
} 