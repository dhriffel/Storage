#include "Triangle.h";
#include "Shape.h";

Shape* New_Triangle(double side1, double side2, double side3, double height) {
	Shape* baseobj = New_Shape();
	Triangle* derivedobj = malloc(sizeof(Triangle));
	derivedobj->side1 = side1;
	derivedobj->side2 = side2;
	derivedobj->side3 = side3;
	derivedobj->height = height;
	baseobj->area = triArea;
	baseobj->perimeter = triPerimeter;
	baseobj->derivedShape = derivedobj;
	return baseobj;
}
double triArea(Shape* shape) {
	Triangle* tri = (Triangle*)shape->derivedShape;
	return ((tri->side1)*(tri->height))/2.0;
}
double triPerimeter(Shape* shape) {
	Triangle* tri = (Triangle*)shape->derivedShape;
	return ((tri->side1)+(tri->side2)+(tri->side3));
}