#ifndef _INITSDL_
#define _INITSDL_

#include <SDL.h>
#include <time.h>
#include <CWindow.h>
#include "stdlib.h"
#include "stdio.h"

extern long elapsedTime;
extern double deltaTime;

void countTime();
bool check24(long* tOld, long* tNew);
void checkExit(CWindow *win);
int initSDL();

#endif