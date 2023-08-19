import MyClass;
import <iostream>;

int main()
{
	MyClass obj {1};
	std::cout << obj.value() << '\n';
	++obj;
	std::cout << obj.value() << '\n';
	obj++;
	std::cout << obj.value() << '\n';
}