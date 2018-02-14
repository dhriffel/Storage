#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 typedef struct person{

		char name[20];
		int age;

		union {
			struct {
				char school[30];
			}child;

			struct {
				char college[30];
				double gpa;
			}collegeStudent;

			struct {
				char company[30];
				int salary;
			}adult;

		}kind;

		enum kindOfPerson{kid, student, adult} kindP;
	}Person;

 void printStruct(Person);

int main()
{
	

	Person p1;
	strcpy(p1.name, "Bob");
	p1.age = 20;
	strcpy(p1.kind.collegeStudent.college, "K-State");
	p1.kindP = student;
	p1.kind.collegeStudent.gpa = 3.5;

	Person *p2 = malloc(sizeof(Person));
	strcpy(p2->name, "Alison");
	p2->age = 10;
	strcpy(p2->kind.child.school, "Amanda Arnold Elementary");
	p2->kindP = kid;

	printStruct(p1);
	printStruct(*p2);
	free(p2);
	return 0;
}

void printStruct(Person p) {
	switch (p.kindP) {
	case kid:
		printf("Name: %s \n", p.name);
		printf("Age: %d \n" , p.age);
		printf("School: %s \n", p.kind.child.school);
		return;
	case student:
		printf("Name: %s \n", p.name);
		printf("Age: %d \n", p.age);
		printf("College: %s \n", p.kind.collegeStudent.college);
		printf("GPA: %f \n", p.kind.collegeStudent.gpa);
		return;
	case adult:
		printf("Name: %s \n", p.name);
		printf("Age: %d \n", p.age);
		printf("College: %s \n", p.kind.adult.company);
		printf("GPA: %d \n", p.kind.adult.salary);
		return;
	default:
		printf("Error with data!");
	}
}