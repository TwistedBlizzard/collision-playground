#ifndef INPUT_H
#define INPUT_H

// SDL

#include "SDL3/SDL.h"

typedef Uint8 InputFlags;

enum InputActions
{
    None = 0,
    Up = 1 << 0,
    Down = 1 << 1,
    Left = 1 << 2,
    Right = 1 << 3
};

#endif