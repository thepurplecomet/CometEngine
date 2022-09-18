#ifndef _RENDER3D_
#define _RENDER3D_

#include <SDL.h>
#include "CWindow.h"
#include "Shapes.h"
#include "Shapes3D.h"
#include <math.h>
#include "Render.h"

typedef struct SpaceCfg {
	int w;
	int h;
	double aspect;
	double fov;
	double renDist;
	double scrDist;
}SpaceCfg;

SpaceCfg newSpaceCfg(double w, double h, double f, double r, double s);
Point3D clip2Screen(Point3D p1, Point3D p2, SpaceCfg cfg);
Point perspectivePoint(Point3D p, SpaceCfg s);
void drawLine3D(Line3D l, Color c, ColorGrid grid, SpaceCfg cfg);
void drawTri3D(Tri3D tri, Color c, ColorGrid grid, SpaceCfg cfg);
void drawSqu3D(Squ3D squ, Color c, ColorGrid grid, SpaceCfg cfg);

#endif