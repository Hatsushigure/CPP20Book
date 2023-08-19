#include "Verbose.h"
#include <memory>
#include <iostream>

auto fn1()
{
	auto ptr1 {std::make_unique<Verbose>()};	//Object #0 is not destroyed for ptr1 is returned out
	auto ptr2 {std::make_unique<Verbose>()};	//Object #1 gets destroyed when the function returns
	//auto ptr3 {ptr1};		//Will not compile
	auto ptr3 {std::move(ptr1)};
	std::cout << "111111111111111111111111111111111111111111111111111111\n";
	return ptr3;
}

auto fn2()
{
	auto ptr1 {std::make_shared<Verbose>()};	//Object #2
	std::cout << ptr1.use_count() << '\n';	//1
	auto ptr2 {ptr1};	//Adds a reference to Object #2
	std::cout << ptr1.use_count() << '\n';	//2
	return ptr2;
}

auto fn3()
{
	struct A
	{
		std::shared_ptr<A> ptr;
		~A() { std::cout << "Oh?\n"; }
	};
	auto a {std::make_shared<A>()};
	a->ptr = a;	//Doing this will cause a to never be destroyed--memory leak!
				//Comment it to see the "Oh?"
}

auto fn4()
{
	struct B
	{
		std::weak_ptr<B> ptr;
		~B() { std::cout << "!\n"; }
	};
	auto b {std::make_shared<B>()};
	b->ptr = std::weak_ptr<B>(b);	//Use weak_ptr to avoid memory leak in fn3()
}

int main()
{
	auto ptr1 {fn1()};
	std::cout << "222222222222222222222222222222222222222222222222222222222222\n";
	auto ptr2 {fn2()};
	std::cout << ptr2.use_count() << '\n';	//1
	fn3();
	fn4();
}