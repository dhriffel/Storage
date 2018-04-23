#include "Person.h"
#include <string.h>

Person* new_Person(const char* const pFirstName, const char* const pLastName) {
	Person* pObj = NULL;
	//allocating memory
	pObj = (Person*)malloc(sizeof(Person));
	if (pObj == NULL)
	{
		return NULL;
	}
	pObj->pFirstName = malloc(sizeof(char)*(strlen(pFirstName) + 1));
	if (pObj->pFirstName == NULL)
	{
		return NULL;
	}
	strcpy(pObj->pFirstName, pFirstName);

	pObj->pLastName= malloc(sizeof(char)*(strlen(pLastName) + 1));
	if (pObj->pLastName == NULL)
	{
		return NULL;
	}
	strcpy(pObj->pLastName, pLastName);

	//Initializing interface for access to functions
	pObj->Delete = delete_Person;
	pObj->Display = Person_DisplayInfo;
	pObj->WriteToFile = Person_WriteToFile;

	return pObj;
}

Person* newPerson(const char* const pFirstName, const char* const pLastName) {
	return NULL;
};
void delete_Person(Person* const pPersonObj) {
	return;
};
void Person_DisplayInfo(Person* const pPersonObj) {
	return;
};
void Person_WriteToFile(Person* const pPersonObj, const char* const pFileName) {
	return;
};