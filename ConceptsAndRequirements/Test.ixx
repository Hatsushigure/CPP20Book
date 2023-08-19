export module Test;
import <concepts>;
import <iostream>;

export namespace Test
{
//A simple concept
template <typename T>
concept MyConcept = (sizeof(T) == sizeof(int));
//Require
template <class T>
concept MyOtherConcept = requires(T x) { x++; ++x; };

template <typename T> requires std::integral<T>
auto func1(T val)
{
	std::cout << val << '\n';
}

template <typename T>
auto func2(T val) requires MyOtherConcept<T>
{
	std::cout << val << '\n';
}

template <std::floating_point T>	//Simplified
auto func3(T val)
{
	std::cout << val << '\n';
}
}