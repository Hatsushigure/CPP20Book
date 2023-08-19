import Test;

int main()
{
	auto a {114};
	size_t b {514};
	auto c {.1919810};
	Test::func1(a);
	//Test::func3(a);	//Not Compile
	Test::func1(b);
	Test::func3(c);
}