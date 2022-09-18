#include "Render3D.h"

SpaceCfg newSpaceCfg(double w, double h, double f, double r, double s) {
	SpaceCfg ret = { w,h,(w/h),f,r,s };
	return ret;
}

Point3D clip2Screen(Point3D p1, Point3D p2, SpaceCfg cfg) {
	Point3D p = double2Point3D(p1.x, p1.y, p1.z);
	printf("p1=%f,%f,%f  p2=%f,%f,%f\n",p1.x,p1.y,p1.z,p2.x,p2.y,p2.z);
	Point3D dVector = double2Point3D((p1.x-p2.x),(p1.y-p2.y),(p1.z-p2.z));
	Point3D normal = double2Point3D(0,0,cfg.scrDist);
	double t = ((cfg.scrDist - p.z) / dVector.z);
	printf("T=%f\n",t);
	Point3D ret = { p.x + (t * dVector.x),p.y + (t * dVector.y),p.z + (t * dVector.z) };
	printf("X=%f\n", ret.x);
	printf("returning:%f,%f,%f\n",ret.x,ret.y,ret.z);
	return ret;
}

Point perspectivePoint(Point3D p, SpaceCfg cfg) {
	double newZ = p.z;
	if (p.z < cfg.scrDist) {
		newZ = cfg.scrDist;
	}
	if (newZ == 0) {
		newZ = 1;
	}
	double newFov = abs(1 / tan(((cfg.fov / 180) * 3.14159265) / 2));
	double newAsp = cfg.w / cfg.h;
	Point ret = { (((newAsp * newFov * p.x) / newZ) * (cfg.h / 2)), (((newFov * p.y) / newZ) * (cfg.h / 2)) };
	return ret;
}

void drawLine3D(Line3D l, Color c, ColorGrid grid, SpaceCfg cfg) {
	Point3D p1;
	Point3D p2;

	Point ret1;
	Point ret2;
	if ((l.points[0].z < cfg.scrDist) && (l.points[1].z < cfg.scrDist)) {
		return;
	}
	else if ((l.points[0].z < cfg.scrDist) && (l.points[1].z >= cfg.scrDist)) {
		Point3D clip = clip2Screen(l.points[0], l.points[1], cfg);
		Point3D same = l.points[1];
		Line draw = point2Line(perspectivePoint(same, cfg), perspectivePoint(clip, cfg));
		drawLine(draw, c, grid);
		return;
	}
	else if (l.points[1].z < cfg.scrDist && l.points[0].z >= cfg.scrDist) {
		Point3D clip = clip2Screen(l.points[1], l.points[0], cfg);
		Point3D same = l.points[0];
		Line draw = point2Line(perspectivePoint(same, cfg),perspectivePoint(clip, cfg));
		drawLine(draw, c, grid);
		return;
	}
	else {
		ret1 = perspectivePoint(l.points[0], cfg);
		ret2 = perspectivePoint(l.points[1], cfg);;
		Line draw = { ret1,ret2 };
		drawLine(draw, c, grid);
		printf("saving z:%f,z:%f\n", l.points[0].z, l.points[1].z);
		return;
	}
}

void drawTri3D(Tri3D tri, Color c, ColorGrid grid, SpaceCfg cfg) {
	drawLine3D(point2Line3D(tri.points[0], tri.points[1]), c, grid, cfg);
	drawLine3D(point2Line3D(tri.points[1], tri.points[2]), c, grid, cfg);
	drawLine3D(point2Line3D(tri.points[2], tri.points[0]), c, grid, cfg);
}

void drawSqu3D(Squ3D squ, Color c, ColorGrid grid, SpaceCfg cfg) {
	drawTri3D(squ.tris[0], c, grid, cfg);
	drawTri3D(squ.tris[1], c, grid, cfg);
}