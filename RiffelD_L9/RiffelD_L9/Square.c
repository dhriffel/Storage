#include "Square.h";
#include "Shape.h";

Shape* New_Square(double side) {
	Shape* baseobj = New_Shape();
	Square* derivedobj = malloc(sizeof(Square));
	derivedobj->sideLength = side;
	baseobj->area = squareArea;
	baseobj->perimeter = squarePerimeter;
	baseobj->derivedShape = derivedobj;
	return baseobj;
}
double squareArea(Shape* shape) {
	Square* square = (Square*)shape->derivedShape;
	return ((square->sideLength)*(square->sideLength));
}
double squarePerimeter(Shape* shape) {
	Square* square = (Square*)shape->derivedShape;
	return ((square->sideLength)*4);
}