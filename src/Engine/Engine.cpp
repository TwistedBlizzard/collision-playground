#include "Engine/Engine.hpp"

#include <memory>
using std::make_shared;

#define SPEED 50

Engine::Engine() :
m_initialised(false),
m_nextID(0),
m_running(false),
m_inputFlags(0),
m_collisionHandler(nullptr),
m_inputManager(nullptr),
m_renderer(nullptr),
m_timing(nullptr)
{}

Engine::~Engine()
{}

void Engine::Init()
{
    if (m_initialised)
        return;

    SDL_Init(SDL_INIT_EVERYTHING);

    m_collisionHandler = make_shared<CollisionHandler>();
    m_inputManager = make_shared<InputManager>(&m_inputFlags);
    m_renderer = make_shared<Renderer>();
    m_timing = make_shared<Timing>();

    m_renderer->Init();
    m_timing->Init();

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

        m_inputManager->HandleEvent(event);
    }

    m_renderer->Clear();

    float deltaTime = m_timing->DeltaTime();

    Vector2f target = Vector2f(512.0f, 384.0f);

    for (auto const &[id, gameObject] : m_gameObjects)
    {
        Vector2f position = gameObject->GetPosition();
        Vector2f deltaPosition = position.Toward(target);
        deltaPosition.x *= SPEED * deltaTime;
        deltaPosition.y *= SPEED * deltaTime;
        gameObject->Move(deltaPosition);
        gameObject->Draw(m_renderer);
    }

    m_collisionHandler->CheckCollision(m_gameObjects);

    m_renderer->Present();

    m_timing->Update();
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

