#include "InitSDL.h"


long elapsedTime = 0;
double frameRate = 0;
double timeInSec = 0;
double deltaTime = 0;

int count = 0;
long check = 0;

void countTime() {
	count++;
	elapsedTime = (long)clock();
	deltaTime = ((long)clock() - timeInSec)/1000;
	timeInSec = (long)clock();
	if ((clock() - 1000) > check) {
		frameRate = count;
		count = 0;
		check = clock();
	}
}

bool check24(long *tOld, long *tNew) {
	if (*tNew-16>=*tOld) {
		*tOld = (long)clock();
		return true;
	}
	else
		return false;
}

void checkExit(CWindow* win) {
	SDL_Event close;
	SDL_PollEvent(&close);
	if (close.type == SDL_QUIT)
	{
		closeWindow(*win);
		win->running = false;
	}
}
int initSDL() {
	SDL_Init(SDL_INIT_VIDEO);
	countTime();
	return 1;
}