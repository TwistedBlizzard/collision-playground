#include "Engine/GameObject.hpp"

using std::make_shared;

GameObject::GameObject(Vector2f position) :
m_initialised(false),
m_position(position),
m_collider(nullptr)
{}

GameObject::GameObject(float posX, float posY) :
m_initialised(false),
m_position(posX, posY),
m_collider(nullptr)
{}

GameObject::~GameObject()
{}

void GameObject::Init()
{
    // Don't init more than once
    if (m_initialised)
        return;

    // Create our collider
    m_collider = make_shared<Collider>(m_position, 10.0f);

    m_initialised = true;
}

Vector2f GameObject::GetPosition()
{
    return m_position;
}

void GameObject::SetPosition(Vector2f position)
{
    m_position = position;
    m_collider->SetPosition(m_position);
}

void GameObject::SetPosition(float posX, float posY)
{
    Vector2f position = Vector2f(posX, posY);
    SetPosition(position);
}

void GameObject::Move(Vector2f deltaPosition)
{
    m_position += deltaPosition;
    m_collider->SetPosition(m_position);
}

void GameObject::Move(float deltaX, float deltaY)
{
    Vector2f deltaPosition = Vector2f(deltaX, deltaY);
    Move(deltaPosition);
}

ColliderPtr GameObject::GetCollider()
{
    return m_collider;
}

void GameObject::Draw(RendererPtr renderer)
{
    m_collider->Draw(renderer);
}
