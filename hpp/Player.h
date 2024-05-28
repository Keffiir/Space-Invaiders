//
// Created by Иван Никифоров on 19.05.2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Bullet.h"
#include <vector>

class Player {
private:
    Texture2D image;
    Vector2 position;
    int speed;

public:
    Player();
    ~Player();
    void MoveLeft();
    void MoveRight();
    void Draw();
    void Fire();
    void Update();
    void ResetPosition();
    Vector2 GetCurrentPosition();
    Rectangle GetRect();
};

#endif //PLAYER_H
