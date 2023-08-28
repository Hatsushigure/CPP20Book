#include <ratio>
#include "../print.h"

int main()
{
	using num1 = std::ratio<1, 2>;
	using num2 = std::ratio<1, 3>;

	using sum = std::ratio_add<num1, num2>::type;	//add	//Should be 1/5(
	using prod = std::ratio_multiply<num1, num2>::type;	//multiply

	std::println("sum = {}/{}", sum::num, sum::den);
	std::println("prod = {}/{}", prod::num, prod::den);
}
