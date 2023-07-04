#ifndef ENGINE_H
#define ENGINE_H

// Standard Library

#include <map>
using std::map;

// SDL

#include "SDL3/SDL.h"

// Engine

#include "CollisionHandler.hpp"
#include "GameObject.hpp"
#include "Renderer.hpp"
#include "Timing.hpp"

class Engine
{
public:
    Engine();
    ~Engine();

    /*******\
    * Setup *
    \*******/

    void Init();

    /********\
    * Update *
    \********/

    void Start();
    bool Running();
    void Update();

    /*************\
    * GameObjects *
    \*************/

    GameObjectPtr CreateGameObject(Vector2f position);

private:
    bool m_initialised;
    bool m_running;

    int m_nextID;
    map<int, GameObjectPtr> m_gameObjects;

    CollisionHandlerPtr m_collisionHandler;
    RendererPtr m_renderer;
    TimingPtr m_timing;
};

#endif