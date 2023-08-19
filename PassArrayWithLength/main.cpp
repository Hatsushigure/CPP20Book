#include <iostream>

auto fn1(int(&arr)[6])
{
	using namespace std;
	for (auto i : arr)
		cout << i << ' ';
	cout << endl;
}

template <size_t N>
auto fn2(int(&arr)[N])
{
	using namespace std;
	for (auto i : arr)
		cout << i << ' ';
	cout << endl;
}

auto fn3(auto... arg)
{
	using namespace std;
	((cout << arg << ' '), ...);
	cout << endl;
}

int main()
{
	using namespace std;
	int arr1[] {1, 2, 3, 4, 5, 6};
	int arr2[] {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
	fn1(arr1);
	//fn1(arr2);	//Will not compile
	fn2(arr1);
	fn2(arr2);
	  fn3(1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0);
}