#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Standard Library

#include <memory>
using std::shared_ptr;

// Engine

#include "Vector2f.hpp"
#include "Collider.hpp"
#include "Renderer.hpp"

class GameObject
{
public:
    GameObject(Vector2f position);
    GameObject(float posX, float posY);
    ~GameObject();

    /*******\
    * Setup *
    \*******/

    void Init();

    /*************\
    * Positioning *
    \*************/

    Vector2f GetPosition();
    void SetPosition(Vector2f position);
    void SetPosition(float posX, float posY);
    void Move(Vector2f deltaPosition);
    void Move(float deltaX, float deltaY);

    /***********\
    * Collision *
    \***********/

    ColliderPtr GetCollider();

    /***********\
    * Rendering *
    \***********/

    void Draw(RendererPtr renderer);

private:
    bool m_initialised;

    Vector2f m_position;
    ColliderPtr m_collider;
};

typedef shared_ptr<GameObject> GameObjectPtr;

#endif