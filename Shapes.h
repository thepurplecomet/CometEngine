#ifndef _SHAPES_
#define _SHAPES_

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include "CWindow.h"

typedef struct Point{
	double x;
	double y;
}Point;
typedef struct Line{
	Point points[2];
}Line;
typedef struct Tri{
	Point points[3];
}Tri;
typedef struct Squ{
	Tri tris[2];
}Squ;
typedef struct Poly{
	Point points[];
}Poly;
Point double2Point(double x, double y);
Point Line2Point(Line l, int i);
Line double2Line(double x1, double y1, double x2, double y2);
Line pointDoubleLine(Point a, double x2, double y2);
Line doublePointLine(double x1, double y1, Point b);
Line point2Line(Point a, Point b);
Tri newTri(Point points[3]);
Squ newSqu(Point origin, double size);
Point rotatePoint(Point p, double deg, CWindow win);
Squ rotateSqu(Squ squ, double deg, CWindow win);
Squ double2Squ(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

#endif