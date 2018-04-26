#pragma once
#include "Shape.h";

typedef struct _Square Square;


typedef struct _Square {
	double sideLength;

}Square;

Shape* New_Square(double);
double squareArea(Shape*);
double squarePerimeter(Shape*);