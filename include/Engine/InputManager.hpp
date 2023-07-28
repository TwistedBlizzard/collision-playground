#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

// Standard Library

#include <memory>
using std::shared_ptr;

// SDL

#include "SDL3/SDL.h"

// Engine

#include "Input.hpp"
#include "Vector2f.hpp"

class InputManager
{
public:
    InputManager(InputFlags* inputFlags);
    ~InputManager();

    /****************\
    * Event Handling *
    \****************/

    void HandleEvent(SDL_Event event);

    /***************\
    * Input Parsing *
    \***************/

    Vector2f GetVector();    

private:
    InputFlags* m_inputFlags;

    static InputActions GetAction(SDL_Keycode code);
    void KeyDown(SDL_Keycode code);
    void KeyUp(SDL_Keycode code);
};

typedef shared_ptr<InputManager> InputManagerPtr;

#endif