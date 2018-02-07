#include <stdio.h>
#include <string.h>

void display(struct student *);

struct student {

		char name[20];
		int age;
		int year;

	};

int main() {

	

	struct student* stuPoint = malloc(sizeof(struct student));
	printf("Enter name of student: ");
	scanf_s("%20[a-zA-Z ]", stuPoint->name, 20);
	printf("Enter age of student: ");
	scanf("%d", &(stuPoint->age));
	printf("Enter year of student (1-4): ");
	scanf("%d", &(stuPoint->year));

	display(stuPoint);
	stuPoint->age++;
	if(stuPoint->year < 4)
		stuPoint->year++;
	display(stuPoint);

	return 1;

}

void display(struct student* stuPoint) {
	printf("Name: %s \n", (*stuPoint).name);
	printf("Age: %d \n", (*stuPoint).age);
	printf("Year: ");

	switch ((*stuPoint).year) {
	case 1:
		printf("Freshman\n");
		break;
	case 2:
		printf("Sophomore\n");
		break;
	case 3:
		printf("Junior\n");
		break;
	case 4:
		printf("Senior\n");
		break;
	default:
		printf("Error\n");
		break;
	}
}