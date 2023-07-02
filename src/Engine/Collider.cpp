#include "Engine/Collider.hpp"

Collider::Collider(Vector2f position, float radius) :
m_position(position),
m_raduis(radius)
{}

Collider::~Collider()
{}

Vector2f Collider::GetPosition()
{
    return m_position;
}

void Collider::SetPosition(Vector2f position)
{
    m_position = position;
}

void Collider::SetPosition(float posX, float posY)
{
    m_position = Vector2f(posX, posY);
}

float Collider::GetRadius()
{
    return m_raduis;
}

void Collider::SetRadius(float radius)
{
    m_raduis = radius;
}

void Collider::Draw(RendererPtr renderer)
{
    renderer->DrawCircle(m_position, m_raduis);
}
