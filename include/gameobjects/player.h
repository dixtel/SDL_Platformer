#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/gameobject.h"

#include "include/vectro2.h"

class Player : public GameObject
{
public:

    Player();

    void Init(Vector2f position, Vector2u size, SDL_Texture *texture);

    void UpdatePhysics(double dt);
    void Update();
    void HandleInput(GameObjectInput input);

    void OnGround();

    Rectangle *GetRectangle();
    RectangleCollision *GetRectangleCollision();

private:

    SDL_Rect destination_texture;

    Rectangle rectangle;
    RectangleCollision rectangle_collision;

    Vector2f position;
    Vector2u size;

    Vector2f velocity;
    float acceleration;
    float speed;
    float jump_force;
    float max_speed;
    float gravity;
    float friction;

    bool is_jump;

    bool jump;
    bool move_right;
    bool move_left;
    bool move_down;
    bool move_up;
};

#endif // PLAYER_H
