#include "Engine/Engine.hpp"

#include <memory>
using std::make_shared;

Engine::Engine() :
m_initialised(false),
m_nextID(0),
m_running(false),
m_collisionHandler(nullptr),
m_renderer(nullptr)
{}

Engine::~Engine()
{}

void Engine::Init()
{
    if (m_initialised)
        return;

    SDL_Init(SDL_INIT_EVERYTHING);

    m_collisionHandler = make_shared<CollisionHandler>();
    m_renderer = make_shared<Renderer>();
    m_renderer->Init();

    m_initialised = true;
}

void Engine::Start()
{
    if (!m_initialised)
        return;

    m_running = true;
}

bool Engine::Running()
{
    return m_running;
}

void Engine::Update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            m_running = false;
            return;
        }
    }

    m_renderer->Clear();

    Vector2f target = Vector2f(512.0f, 384.0f);

    for (auto const &[id, gameObject] : m_gameObjects)
    {
        Vector2f position = gameObject->GetPosition();
        Vector2f deltaPosition = position.Toward(target);
        deltaPosition.x *= 0.01;
        deltaPosition.y *= 0.01;
        gameObject->Move(deltaPosition);
        gameObject->Draw(m_renderer);
    }

    m_collisionHandler->CheckCollision(m_gameObjects);

    m_renderer->Present();
}

GameObjectPtr Engine::CreateGameObject(Vector2f position)
{
    GameObjectPtr gameObject = make_shared<GameObject>(position);
    gameObject->Init();
    m_collisionHandler->Register(gameObject);

    m_gameObjects[m_nextID] = gameObject;
    m_nextID++;

    return gameObject;
}

