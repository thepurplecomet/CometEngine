
#include "Shapes.h"

Point double2Point(double x,double y) {
	Point point = { x,y };
	return point;
}
Point Line2Point(Line l, int i) {
	return l.points[i-1];
}
Line double2Line(double x1,double y1,double x2,double y2) {
	Point a = { x1,y1 };
	Point b = { x2,y2 };
	Line l = {a,b};
	return l;
}
Line pointDoubleLine(Point a, double x2, double y2) {
	Point b = { x2,y2 };
	Line l = { a,b };
	return l;
}
Line doublePointLine(double x1, double y1, Point b) {
	Point a = { x1,y1 };
	Line l = { a,b };
	return l;
}
Line point2Line(Point a, Point b){
	Line l = { a,b };
	return l;
}
Tri newTri(Point points[3]) {
	Tri t = { points[0],points[1],points[2], };
	return t;
}
Squ newSquare(Point origin, double size) {
	Point arr1[3] = { origin,
					double2Point(origin.x,origin.y + size),
					double2Point(origin.x + size,origin.y + size) };
	Tri t1 = newTri(arr1);
	Point arr2[3] = { origin,
					double2Point(origin.x + size,origin.y + size),
					double2Point(origin.x + size,origin.y) };
	Tri t2 = newTri(arr2);
	Squ ret = { t1,t2 };
	return ret;
}
Point rotatePoint(Point p, double deg, CWindow win) {
	double rads = deg * 0.01745329;
	double s = sin(rads);
	double c = cos(rads);

	Point buffer = { (p.x - 400),(p.y - 300) };

	double x = buffer.x * c - buffer.y * s;
	double y = buffer.x * s + buffer.y * c;

	Point ret = { (x + 400),(y + 300) };
	return ret;
}
Squ rotateSquare(Squ squ, double deg, CWindow win) {
	Point p1 = rotatePoint(squ.tris[0].points[0], deg, win);
	Point p2 = rotatePoint(squ.tris[0].points[1], deg, win);
	Point p3 = rotatePoint(squ.tris[0].points[2], deg, win);
	Point p4 = rotatePoint(squ.tris[1].points[0], deg, win);
	Point p5 = rotatePoint(squ.tris[1].points[1], deg, win);
	Point p6 = rotatePoint(squ.tris[1].points[2], deg, win);
	Tri t1 = { p1,p2,p3 };
	Tri t2 = { p4,p5,p6 };
	Squ ret = { t1,t2 };
	return ret;
}
Squ point2Square(Point p1, Point p2, Point p3, Point p4) {
	Tri t1 = { p1,p2,p3 };
	Tri t2 = { p1,p3,p4 };
	Squ squ = {t1, t2};
	return squ;
}
Squ double2Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	Tri t1 = { double2Point(x1,y1),double2Point(x2,y2),double2Point(x3,y3) };
	Tri t2 = { double2Point(x1,y1),double2Point(x3,y3),double2Point(x4,y4) };
	Squ squ = {t1,t2};
	return squ;
}
