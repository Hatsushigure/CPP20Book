export module MyClass;
import <utility>;

export class MyClass
{
private:
	int m_value;
public:
	explicit MyClass(int val) : m_value {val} {}
public:
	auto value() const { return m_value; }
	void setValue(int val) { m_value = val; }
public:
	auto& operator++()	//Prefix
	{
		m_value++;
		return *this;
	}

	auto operator++(int)	//suffix
	{
		MyClass tmp {*this};
		m_value++;
		return tmp;
	}
};
