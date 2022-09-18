#ifndef _CWINDOW_H_
#define _CWINDOW_H_

#include <SDL.h>
#include <stdbool.h>

typedef struct CWindow {
	SDL_Window* win;
	int w;
	int h;
	bool running;
}CWindow;
CWindow newWindow(char title[15], int x, int y);
void closeWindow(struct CWindow win);

#endif