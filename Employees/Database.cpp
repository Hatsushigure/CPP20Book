#include "Database.h"
#include "Employee.h"
#include <iostream>

using std::cout, std::endl;

Employee* Database::addEmployee(const string& firstName, const string& lastName, const int level)
{
	auto newEmployee {new Employee(firstName, lastName, level)};
	m_employees.insert({newEmployee->id(), newEmployee});
	return newEmployee;
}

Employee* Database::findEmployee(const unsigned id)
{
	auto it {m_employees.find(id)};
	if (it == m_employees.end())
		return nullptr;
	return it->second;
}

void Database::diaplayAll()
{
	for (auto& emp : m_employees)
	{
		emp.second->printInfo();
		cout << endl;
	}
	cout << "Done!\n";
}

void Database::displayCurrent()
{
	for (auto& emp : m_employees)
	{
		if (emp.second->isFormer())
			continue;
		emp.second->printInfo();
		cout << endl;
	}
	cout << "Done!\n";
}

void Database::displayFormer()
{
	for (auto& emp : m_employees)
	{
		if (!emp.second->isFormer())
			continue;
		emp.second->printInfo();
		cout << endl;
	}
	cout << "Done!\n";
}
