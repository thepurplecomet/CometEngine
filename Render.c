#include "Render.h"

ColorGrid newColorGrid(struct CWindow win) {
	int w = win.w;
	int h = win.h;
	ColorGrid renderer = {w,h,SDL_CreateRenderer(win.win, -1, 0)};
	return renderer;
}

void drawLine(Line l, Color c, ColorGrid ren) {
	SDL_SetRenderDrawColor(ren.ren, c.r, c.g, c.b, c.a);
	Point p1 = { (l.points[0].x + (round(ren.w / 2))),(-l.points[0].y + (round(ren.h / 2))) };
	Point p2 = { (l.points[1].x + (round(ren.w / 2))),(-l.points[1].y + (round(ren.h / 2))) };

	SDL_RenderDrawLine(
		ren.ren,
		round(p1.x),
		round(p1.y),
		round(p2.x),
		round(p2.y)
	);
}

void drawTri(Tri t, Color col, ColorGrid grid) {
	Line l1 = { t.points[0],t.points[1] };
	Line l2 = { t.points[1],t.points[2] };
	Line l3 = { t.points[2],t.points[0] };

	drawLine(l1, col, grid);
	drawLine(l2, col, grid);
	drawLine(l3, col, grid);
}

void refreshWindow(ColorGrid grid) {
	SDL_RenderPresent(grid.ren);
	SDL_SetRenderDrawColor(grid.ren, 0, 0, 0, 0);
	SDL_RenderClear(grid.ren);
}

void drawSqu(Squ squ, Color col, ColorGrid grid) {
	drawTri(squ.tris[0], col, grid);
	drawTri(squ.tris[1], col, grid);
}