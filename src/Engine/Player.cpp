#include "Engine/Player.hpp"

#define PLAYER_COLLIDER_RADIUS 50.0f
#define PLAYER_SPEED 75.0f

using std::make_shared;

Player::Player(Vector2f position) :
GameObject(position),
m_speed(PLAYER_SPEED)
{}

Player::Player(float posX, float posY) :
GameObject(posX, posY),
m_speed(PLAYER_SPEED)
{}

Player::~Player()
{}

void Player::Init()
{
    // Don't init more than once
    if (m_initialised)
        return;

    // Create our collider
    m_collider = make_shared<Collider>(m_position, PLAYER_COLLIDER_RADIUS);

    m_initialised = true;
}

float Player::GetSpeed()
{
    return m_speed;
}