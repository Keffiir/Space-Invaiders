#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

class Bullet {
public:
    Bullet(Vector2 position, int speed);
    void Update();
    void Draw();
    bool IsActive();
private:
    Vector2 pos;
    int speed;
    bool active;
};



#endif
