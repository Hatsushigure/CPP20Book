#include "Employee.h"
#include <iostream>
#include <format>

using std::cout, std::format;

unsigned Employee::nextId {0};

Employee::Employee(const string& firstName, const string& lastName, const int level)
	: m_firstName {firstName},
	m_lastName {lastName},
	m_level {level}
{
	m_id = nextId;
	nextId++;
}

void Employee::printInfo()
{
	cout << format("+{:-^20}+{:-^40}+\n", "", "")
		<< format("|{:^20}|{:^40}|\n", "id", id())
		<< format("+{:-^20}+{:-^40}+\n", "", "")
		<< format("|{:^20}|{:^40}|\n", "Name", firstName() + " " + lastName())
		<< format("+{:-^20}+{:-^40}+\n", "", "")
		<< format("|{:^20}|{:^40}|\n", "Current Employee", isFormer() ? "No" : "Yes")
		<< format("+{:-^20}+{:-^40}+\n", "", "")
		<< format("|{:^20}|{:^40}|\n", "Level", level())
		<< format("+{:-^20}+{:-^40}+\n", "", "")
		<< format("|{:^20}|{:^40}|\n", "Salary", salary())
		<< format("+{:-^20}+{:-^40}+\n", "", "");
}
