#ifndef _RENDER_
#define _RENDER_

#include <SDL.h>
#include "CWindow.h"
#include "Shapes.h"
#include <math.h>

typedef struct ColorGrid {
	int w;
	int h;
	SDL_Renderer* ren;
}ColorGrid;

typedef struct Color {
	int r;
	int g;
	int b;
	int a;
}Color;

ColorGrid newColorGrid(struct CWindow win);
void drawLine(Line l, Color c, ColorGrid ren);
void drawTri(Tri t, Color col, ColorGrid grid);
void refreshWindow(ColorGrid ren);
void drawSqu(Squ squ, Color col, ColorGrid grid);

#endif