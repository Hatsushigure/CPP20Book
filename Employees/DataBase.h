#pragma once
#include <string>
#include <unordered_map>

class Employee;
using EmployeeMap = std::unordered_map<unsigned, Employee*>;
using std::string;

class Database
{
private:
	EmployeeMap m_employees;
public:
	Employee* addEmployee(const string& firstName, const string& lastName, const int level = 0);
	Employee* hireEmployee(const string& firstName, const string& lastName, const int level = 0) { return addEmployee(firstName, lastName, level); }
	Employee* findEmployee(const unsigned id);
	void diaplayAll();
	void displayCurrent();
	void displayFormer();
};