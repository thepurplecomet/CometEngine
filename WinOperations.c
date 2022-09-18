#include <SDL.h>
#include "Shapes.h"

Point getMousePosition(void)
{
    Point ret;
    SDL_GetMouseState(&ret.x, &ret.y);

    return ret;
}