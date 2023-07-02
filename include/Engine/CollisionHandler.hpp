#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

// Standard Library

#include <memory>
using std::shared_ptr;

#include <set>
using std::set;

#include <map>
using std::map;

// Engine

#include "GameObject.hpp"
#include "Collider.hpp"

class CollisionHandler
{
public:
    CollisionHandler();
    ~CollisionHandler();

    /********\
    * Update *
    \********/

    void Update(map<int, GameObjectPtr> gameObjects);

    /***********\
    * Collision *
    \***********/

    

    /**************\
    * Registration *
    \**************/

    void Register(GameObjectPtr gameObject);
    void Register(ColliderPtr collider);
    void Unregister(GameObjectPtr gameObject);
    void Unregister(ColliderPtr collider);

private:
    set<ColliderPtr> m_colliders;
};

typedef shared_ptr<CollisionHandler> CollisionHandlerPtr;

#endif