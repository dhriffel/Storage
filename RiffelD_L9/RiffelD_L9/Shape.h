#pragma once

typedef struct _Shape Shape;

typedef double (*fptrArea)(Shape*);
typedef double (*fptrPerimeter)(Shape*);

typedef struct _Shape {
	void* derivedShape;
	fptrArea area;
	fptrPerimeter perimeter;
}Shape;

Shape* New_Shape();
