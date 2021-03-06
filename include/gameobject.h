#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/vectro2.h"

enum GameObjectInput {
    RIGHT_ON,
    RIGHT_OFF,
    LEFT_ON,
    LEFT_OFF,
    DOWN_ON,
    DOWN_OFF,
    UP_ON,
    UP_OFF,
    CLICK_ON_OBJECT_ON,
    CLICK_ON_OBJECT_OFF
};

class GameObject
{
public:

    virtual ~GameObject() {}

    virtual void Init(Vector2f position, Vector2u size, SDL_Texture *texture) = 0;
    virtual void UpdatePhysics(double dt) = 0;
    virtual void Update() = 0;
    virtual void HandleInput(GameObjectInput input) = 0;
    virtual void OnGround() {}

    virtual Rectangle *GetRectangle() = 0;
    virtual RectangleCollision *GetRectangleCollision() = 0;
};


#endif // GAMEOBJECT_H
