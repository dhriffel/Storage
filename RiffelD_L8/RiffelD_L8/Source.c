#include <stdio.h>
#include "Person.h"
#include "Employee.h"

int main(int argc, const char * argv[]) {
	Person* PersonObj = new_Person("Alice", "Sun");
	Person* EmployeeObj = new_Employee("Bob", "Smith", "HR", "TCS", 40000);

	//accessing person object

	//displaying person info
	PersonObj->Display(PersonObj);
	//writing person info in the persondata.txt file
	PersonObj->WriteToFile(PersonObj, "persondata.txt");
	//calling destructor
	PersonObj->Delete(PersonObj);

	//accessing to employee object

	//displaying employee info
	EmployeeObj->Display(EmployeeObj);
	//writing employee info in the employeedata.txt file
	EmployeeObj->WriteToFile(EmployeeObj, "employeedata.txt");
	//calling destructor
	EmployeeObj->Delete(EmployeeObj);
	return 0;

}