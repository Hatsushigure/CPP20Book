#include <iostream>
#include <format>
#include <array>
import Employee;

void printEmployee(const HR::Employee& emp);

int main()
{
	using HR::Employee, HR::EmployeeTitle;
	using std::array;
	array<Employee, 3> empArr;
	empArr[0] = {
		.firstInitial = 'A',
		.lastInitial = 'a',
		.employeeNumber = 0,
		.salary = 111111
	};
	empArr[1] = {
		.firstInitial = 'B',
		.lastInitial = 'b',
		.employeeNumber = 1,
		.salary = 222222
	};
	empArr[2] = {
		.firstInitial = 'C',
		.lastInitial = 'c',
		.employeeNumber = 2,
		.salary = 222222
	};

	for (auto& emp : empArr)
		printEmployee(emp);
}

void printEmployee(const HR::Employee& emp)
{
	using HR::Employee, HR::EmployeeTitle;
	using std::cout, std::format, std::string;

	string titleString;
	switch (emp.title)
	{
	case EmployeeTitle::Engineer:
		titleString = "Engineer";
		break;
	case EmployeeTitle::SuperiorEngineer:
		titleString = "SuperiorEngineer";
		break;
	case EmployeeTitle::Manager:
		titleString = "Manager";
		break;
	}

	cout << format("Employee {}{} with employee number {}\n",
				   emp.firstInitial,
				   emp.lastInitial,
				   emp.employeeNumber
	);
	cout << format("Salary is ${}\n",
				   emp.salary
	);
	cout << format("His/Her title is {}\n", 
				   titleString
	);
}
