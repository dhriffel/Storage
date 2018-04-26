#pragma once
#include "Shape.h";

typedef struct _Triangle Triangle;


typedef struct _Triangle {
	double side1;
	double side2;
	double side3;
	double height;

}Triangle;

Shape* New_Triangle(double);
double triArea(Shape*);
double triPerimeter(Shape*);