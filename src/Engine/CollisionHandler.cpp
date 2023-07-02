#include "Engine/CollisionHandler.hpp"

#include <map>
using std::map;

CollisionHandler::CollisionHandler()
{}

CollisionHandler::~CollisionHandler()
{}

void CollisionHandler::CheckCollision(map<int, GameObjectPtr> gameObjects)
{
    map<int, Vector2f> collisions;
    for (auto const &[id, gameObject] : gameObjects)
    {
        ColliderPtr collider = gameObject->GetCollider();
        Vector2f force = CheckCollision(collider);
        collisions[id] = force;
    }

    for (auto const &[id, deltaPosition] : collisions)
        gameObjects[id]->Move(deltaPosition);
}

Vector2f CollisionHandler::CheckCollision(ColliderPtr collider)
{
    Vector2f totalForce = Vector2f();

    // Check if collider is valid
    if(!collider)
        return totalForce;

    Vector2f position = collider->GetPosition();
    float radius = collider->GetRadius();

    for (auto const other : m_colliders)
    {
        // Don't check a collider against itself
        if (collider == other)
            continue;

        Vector2f otherPosition = other->GetPosition();
        float otherRadius = other->GetRadius();

        // Get the distance between colliders
        float distance = position.Distance(otherPosition);

        // Calculate the threshold for a collision
        float threshold = radius + otherRadius;

        // Check for a collision
        if (distance > threshold)
            continue;

        // Calculate the overlap of the colliders
        float overlap = threshold - distance;

        // Get the vector of the force
        Vector2f force = otherPosition.Toward(position);

        // Scale the force
        float forceScale = overlap / threshold;
        forceScale *= radius;
        force.x *= forceScale;
        force.y *= forceScale;

        // Add the force to the total force
        totalForce += force;
    }

    return totalForce;
}

void CollisionHandler::Register(GameObjectPtr gameObject)
{
    ColliderPtr collider = gameObject->GetCollider();
    Register(collider);
}

void CollisionHandler::Register(ColliderPtr collider)
{
    if (!collider)
        return;

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
