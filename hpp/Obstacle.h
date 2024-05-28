//
// Created by Иван Никифоров on 27.05.2024.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

class Obstacle {
private:
    Vector2 position;
public:
    Obstacle(Vector2 position, Color color);
    void Update();
    void Draw();
    bool IsActive();
    Rectangle GetRect();
    int lives = 8;
    Color color;
};



#endif //OBSTACLE_H
