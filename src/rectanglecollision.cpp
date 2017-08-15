#include "include/rectanglecollision.h"

RectangleCollision::RectangleCollision() {

    current_position = {0, 0};
    old_position = {0, 0};
}

Vector2f RectangleCollision::GetCurrentPoint(char point) {

    switch (point) {
    case 'A':

        return current_point_a;
    case 'B':

        return current_point_b;
    case 'C':

        return current_point_c;
    case 'D':

        return current_point_d;
    default:

        return {0, 0};
    }
}

Vector2f RectangleCollision::GetOldPoint(char point) {

    switch (point) {
    case 'A':

        return old_point_a;
    case 'B':

        return old_point_b;
    case 'C':

        return old_point_c;
    case 'D':

        return old_point_d;
    default:

        return {0, 0};
    }
}

void RectangleCollision::SetPosition(Vector2f position) {

    old_position = current_position;
    current_position = position;
    Update();
}

void RectangleCollision::SetSize(Vector2u size) {

    this->size = size;
    Update();
}

Vector2f RectangleCollision::GetPosition() {

    return current_position;
}

void RectangleCollision::SetCollisionPosition(Vector2f position) {

    old_position = position;
    current_position = position;
    Update();
}

void RectangleCollision::Update() {

    old_point_a = current_point_a;
    old_point_b = current_point_b;
    old_point_c = current_point_c;
    old_point_d = current_point_d;

    current_point_a = current_position;
    current_point_b = current_position + Vector2f {size.x, 0};
    current_point_c = current_position + Vector2f {size.x, size.y};
    current_point_d = current_position + Vector2f {0, size.y};
}