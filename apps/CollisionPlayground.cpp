#include "Engine/Engine.hpp"

#define FRAMES 10000

int main()
{
    Engine* engine = new Engine();

    engine->Init();

    engine->CreateGameObject(Vector2f(100.0f, 10.0f));
    GameObjectPtr gameObject = engine->CreateGameObject(Vector2f(10.0f, 100.0f));
    ColliderPtr collider = gameObject->GetCollider();
    collider->SetRadius(20.0f);
    engine->CreateGameObject(Vector2f(400.0f, 20.0f));
    // engine->CreateGameObject(Vector2f(512.0f, 384.0f));

    engine->Start();

    while (engine->Running())
        engine->Update();

    return 0;
}