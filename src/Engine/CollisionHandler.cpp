#include "Engine/CollisionHandler.hpp"

#include <map>
using std::map;

CollisionHandler::CollisionHandler()
{}

CollisionHandler::~CollisionHandler()
{}

void CollisionHandler::Update(map<int, GameObjectPtr> gameObjects)
{
    map<int, Vector2f> collisions;
    for (auto const &[id, gameObject] : gameObjects)
    {
        ColliderPtr collider = gameObject->GetCollider();

        Vector2f position = collider->GetPosition();
        float radius = collider->GetRadius();

        for (auto other : m_colliders)
        {
            if (collider == other)
                continue;

            Vector2f otherPosition = other->GetPosition();
            float distance = position.Distance(otherPosition);

            float otherRadius = other->GetRadius();
            float threshold = radius + otherRadius;

            if (distance > threshold)
                continue;
            
            float overlap = threshold - distance;
            overlap /= threshold;
            overlap *= radius;

            Vector2f deltaPosition = position.Toward(otherPosition);
            deltaPosition.x *= -overlap;
            deltaPosition.y *= -overlap;

            if (collisions.contains(id))
                collisions[id] += deltaPosition;
            else
                collisions[id] = deltaPosition;
        }
    }

    for (auto const &[id, deltaPosition] : collisions)
        gameObjects[id]->Move(deltaPosition);
}

void CollisionHandler::Register(GameObjectPtr gameObject)
{
    ColliderPtr collider = gameObject->GetCollider();
    Register(collider);
}

void CollisionHandler::Register(ColliderPtr collider)
{
    m_colliders.insert(collider);
}

void CollisionHandler::Unregister(GameObjectPtr gameObject)
{
    ColliderPtr collider = gameObject->GetCollider();
    Unregister(collider);
}

void CollisionHandler::Unregister(ColliderPtr collider)
{
    m_colliders.erase(collider);
}
