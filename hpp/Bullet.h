#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

class Bullet {
public:
    Bullet(Vector2 position, int speed);
    void Update();
    void Draw();
    bool IsActive();
    Rectangle GetRect();
    bool active;
    int speed;
private:
    Vector2 pos;
};



#endif
