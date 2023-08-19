#include "Employee.h"
#include "Database.h"
#include <iostream>
#include <format>

using std::cout, std::cin, std::format;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doChangeSalary(Database& db);

int main()
{
	Database employeeDB {};
	bool done {false};
	while (!done)
	{
		int selection {displayMenu()};
		switch (selection)
		{
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			doChangeSalary(employeeDB);
			break;
		case 5:
			employeeDB.diaplayAll();
			break;
		case 6:
			employeeDB.displayCurrent();
			break;
		case 7:
			employeeDB.displayFormer();
			break;
		default:
			cout << "Unknown choice\n";
			break;
		}
	}
}

int displayMenu()
{
	// Note:
	//		One important note is that this code assumes that the user will
	//		"play nice" and type a number when a number is requested.
	//		When you read about I/O in Chapter 13, you will learn how to
	//		protect against bad input.

	int selection;

	cout << '\n'
		<< "Employee Database\n";
	cout << "-----------------\n"
		<< "1) Hire a new employee\n"
		<< "2) Fire an employee\n"
		<< "3) Promote an employee\n"
		<< "4) Chamge salary\n"
		<< "5) List all employees\n"
		<< "6) List all current employees\n"
		<< "7) List all former employees\n"
		<< "0) Quit\n\n"
		<< "---> ";

	cin >> selection;

	return selection;

}

void doHire(Database& db)
{
	string firstName;
	string lastName;

	cout << "First name? ";
	cin >> firstName;

	cout << "Last name? ";
	cin >> lastName;

	auto employee {db.hireEmployee(firstName, lastName)};
	cout << format("Hired employee {} {} with employee number {}.\n",
				   firstName, lastName, employee->id());
}

void doFire(Database& db)
{
	int employeeNumber;
	cout << "Employee number? ";
	cin >> employeeNumber;

	auto emp {db.findEmployee(employeeNumber)};
	emp->unemploy();
}

void doPromote(Database& db)
{
	cout << "Not supported yet!\n";
}

void doChangeSalary(Database& db)
{
	unsigned id, salary;
	cout << "Employee ID? ";
	cin >> id;
	auto emp {db.findEmployee(id)};
	cout << "New salary? ";
	cin >> salary;
	emp->setSalary(salary);
}
