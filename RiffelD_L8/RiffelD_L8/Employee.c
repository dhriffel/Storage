#include "Employee.h"
#include "Person.h"
#include <string.h>


Person* new_Employee(const char* const pFirstName, const char* const pLastName,
	const char* const pDepartment, const char* const pCompany,
	int nSalary) {
	Employee* pObj = NULL;

	pObj = (Employee*)malloc(sizeof(Employee));
	if (pObj == NULL)
	{
		return NULL;
	}
	pObj->pBaseObj = new_Person(pFirstName, pLastName);
	if (pObj->pBaseObj == NULL) {
		return NULL;
	}
	pObj->pDepartment = malloc(sizeof(char) * sizeof(pDepartment) + 1);
	if (pObj->pDepartment == NULL) {
		return NULL;
	}
	pObj->pCompany = malloc(sizeof(char) * sizeof(pCompany) + 1);
	if (pObj->pCompany == NULL) {
		return NULL;
	}

	pObj->pBaseObj->Delete = delete_Person;
	pObj->pBaseObj->Display = Person_DisplayInfo;
	pObj->pBaseObj->WriteToFile = Person_WriteToFile;

	return pObj;
};	//constructor
void delete_Employee(Person* const pPersonObj) {
	return;
};
void Employee_DisplayInfo(Person* const pPersonObj) {
	return;
};
void Employee_WriteToFile(Person* const pPersonObj, const char* const pFileName) {
	return;
};