#include "CWindow.h"

CWindow newWindow(char title[15], int x, int y) {
	struct CWindow window = { SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		x,
		y,
		SDL_WINDOW_OPENGL
	), x, y, true };
	return window;
}

void closeWindow(struct CWindow win) {
	SDL_DestroyWindow(win.win);
}