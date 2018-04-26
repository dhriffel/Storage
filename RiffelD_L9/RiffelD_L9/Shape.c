#include "Shape.h";
#include <stdio.h>;

Shape* New_Shape() {
	Shape* pobj = NULL;
	pobj = (Shape*)malloc(sizeof(Shape));
	if (pobj == NULL)
		return NULL;
	return pobj;
}