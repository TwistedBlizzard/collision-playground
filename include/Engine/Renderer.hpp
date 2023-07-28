#ifndef RENDERER_H
#define RENDERER_H

// Standard Library

#include <memory>
using std::shared_ptr;

// SDL

#include "SDL3/SDL.h"

// Engine

#include "Vector2f.hpp"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    /*******\
    * Setup *
    \*******/

    void Init();

    /********\
    * Window *
    \********/

    Vector2f GetWindowSize();

    /********\
    * Screen *
    \********/

    void Clear();
    void Present();

    /*********\
    * Drawing *
    \*********/

    void DrawCircle(Vector2f position, float radius);

private:
    bool m_initialised;
    SDL_Renderer* m_renderer;
};

typedef shared_ptr<Renderer> RendererPtr;

#endif