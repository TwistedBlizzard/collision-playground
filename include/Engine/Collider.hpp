#ifndef COLLIDER_H
#define COLLIDER_H

// Standard Library

#include <memory>
using std::shared_ptr;

// Engine

#include "Vector2f.hpp"
#include "Renderer.hpp"

class Collider
{
public:
    Collider(Vector2f position, float radius);
    ~Collider();

    /*************\
    * Positioning *
    \*************/

    Vector2f GetPosition();
    void SetPosition(Vector2f position);
    void SetPosition(float posX, float posY);

    /***********\
    * Collision *
    \***********/

    float GetRadius();
    void SetRadius(float radius);

    /***********\
    * Rendering *
    \***********/

    void Draw(RendererPtr renderer);

private:
    Vector2f m_position;
    float m_raduis;
};

typedef shared_ptr<Collider> ColliderPtr;

#endif