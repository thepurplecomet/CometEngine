#include "Shapes3D.h"

Point3D double2Point3D(double x, double y, double z) {
	Point3D p = { x,y,z };
	return p;
}
Point3D line2Point3D(Line3D l, int i) {
	Point3D p = l.points[i - 1];
	return p;
}
Line3D double2Line3D(double x1, double y1, double z1, double x2, double y2, double z2) {
	Point3D p1 = double2Point3D(x1,y1,z1);
	Point3D p2 = double2Point3D(x2, y2, z2);
	Line3D ret = { p1,p2 };
	return ret;
}
Line3D pointDoubleLine3D(Point3D p, double x, double y, double z) {
	Line3D ret = { p, double2Point3D(x,y,z) };
	return ret;
}
Line3D doublePointLine3D(double x, double y, double z, Point3D p) {
	Line3D ret = { double2Point3D(x,y,z), p };
	return ret;
}
Line3D point2Line3D(Point3D p1, Point3D p2) {
	Line3D ret = { p1,p2 };
	return ret;
}
Tri3D newTri3D(Point3D points[3]) {
	Tri3D ret = {points[0],points[1],points[2] };
	return ret;
}
Squ3D newSqu3D(Point3D origin, double size) {
	Point3D arr1[3] = { origin,
					double2Point3D(origin.x,origin.y + size, origin.z),
					double2Point3D(origin.x + size,origin.y + size, origin.z) };
	Tri3D t1 = newTri3D(arr1);
	Point3D arr2[3] = { origin,
					double2Point3D(origin.x + size,origin.y + size, origin.z),
					double2Point3D(origin.x + size,origin.y, origin.z) };
	Tri3D t2 = newTri3D(arr2);
	Squ3D ret = { t1,t2 };
	return ret;
}

void rotateSqu3DY(Squ3D *s, Point3D origin, double theta) {
	Squ3D *ret = s;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 3; i++) {
			float sn = sin((-theta*3.141592653589)/180);
			float cs = cos((-theta*3.141592653589)/180);

			// translate point back to origin:
			double xtemp = s->tris[j].points[i].x - origin.x;
			double ztemp = s->tris[j].points[i].z - origin.z;

			double ytemp = s->tris[j].points[i].y;

			// rotate point
			double xnew = xtemp * cs - ztemp * sn;
			double znew = xtemp * sn + ztemp * cs;

			// translate point back:
			xtemp = xnew + origin.x;
			ztemp = znew + origin.z;

			ret->tris[j].points[i] = double2Point3D(xtemp, ytemp, ztemp);
		}
	}
	*s = *ret;
}
void transSqu3DZ(Squ3D* s, double mag){
	Squ3D* ret = s;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 3; i++) {
			ret->tris[j].points[i].z += mag;
		}
	}
	*s = *ret;
}