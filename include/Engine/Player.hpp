#ifndef PLAYER_H
#define PLAYER_H

// Standard Library

#include <memory>
using std::shared_ptr;

// Engine

#include "GameObject.hpp"

class Player : public GameObject
{
public:
    Player(Vector2f position);
    Player(float posX, float posY);
    ~Player();

    /*******\
    * Setup *
    \*******/

    void Init() override;

    /**********\
    * Movement *
    \**********/

    float GetSpeed();

private:
    float m_speed;
};

typedef shared_ptr<Player> PlayerPtr;

#endif