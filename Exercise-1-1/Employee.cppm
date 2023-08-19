export module Employee;

namespace HR
{
export enum class EmployeeTitle {Manager, SuperiorEngineer, Engineer};
export struct Employee
{
	char firstInitial;
	char lastInitial;
	int employeeNumber;
	int salary;
	EmployeeTitle title {EmployeeTitle::Engineer};
};
}