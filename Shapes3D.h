#ifndef _SHAPES3D_
#define _SHAPES3D_

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include "CWindow.h"
#include "Shapes.h"

typedef struct Point3D {
	double x;
	double y;
	double z;
}Point3D;
typedef struct Line3D {
	Point3D points[2];
}Line3D;
typedef struct Tri3D {
	Point3D points[3];
}Tri3D;
typedef struct Squ3D {
	Tri3D tris[2];
}Squ3D;
typedef struct Cube {
	Tri3D Squ3D[6];
}Cube;
Point3D double2Point3D(double x, double y, double z);
Point3D line2Point3D(Line3D l, int i);
Line3D double2Line3D(double x1, double y1, double z1, double x2, double y2, double z2);
Line3D pointDoubleLine3D(Point3D p, double x, double y, double z);
Line3D doublePointLine3D(double x, double y, double z, Point3D p);
Line3D point2Line3D(Point3D p1, Point3D p2);
Tri3D newTri3D(Point3D points[3]);
Squ3D newSqu3D(Point3D origin, double size);
void rotateSqu3DY(Squ3D *s, Point3D origin, double theta);
void transSqu3DZ(Squ3D* s, double mag);
//Cube newCube(Point3D origin, double size);

#endif