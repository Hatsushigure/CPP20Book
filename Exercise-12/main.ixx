import KeyValuePair;
import <iostream>;

int main()
{
	using namespace Hatsushigure;
	auto myPair1 {KeyValuePair(114, 0.514)};
	std::cout << myPair1.key() << ' ' << myPair1.value() << '\n';
}