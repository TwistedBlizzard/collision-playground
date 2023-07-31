#include "Engine/Engine.hpp"

#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution distX(0, 200 * 1024);
    uniform_int_distribution distY(0, 200 * 768);
    uniform_int_distribution distR(5, 40);

    Engine* engine = new Engine();

    engine->Init();

    for (int i = 0; i < 300; ++i)
    {
        float x = 0.01f * distX(gen);
        float y = 0.01f * distY(gen);
        int r = distR(gen);

        GameObjectPtr go = engine->CreateGameObject(Vector2f(x, y));
        // go->GetCollider()->SetRadius(r);
    }

    engine->Start();

    while (engine->Running())
        engine->Update();

    return 0;
}