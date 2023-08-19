#pragma once
#include <string>

using std::string;

class Employee
{
private:
	static unsigned nextId;
private:
	string m_firstName {};
	string m_lastName {};
	unsigned m_id {};
	int m_level {};
	unsigned m_salary {};
	bool m_isFormal {false};
public:
	Employee(const string& firstName = "", const string& lastName = "", const int level = 0);
public:
	auto firstName() const { return m_firstName; }
	void setFirstName(const string& newFirstName) { m_firstName = newFirstName; }
	auto lastName() const { return m_lastName; }
	void setLastName(const string& newLastName) { m_lastName = newLastName; }
	auto id() const { return m_id; }
	auto level() const { return m_level; }
	void promote() { m_level++; }
	void demote() { m_level--; }
	auto salary() const { return m_salary; }
	void setSalary(const unsigned newSalary) { m_salary = newSalary; }
	auto isFormer() const { return m_isFormal; }
	void unemploy() { m_isFormal = true; }
public:
	void printInfo();
};
