//
// Created by Иван Никифоров on 24.05.2024.
//

#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

#include "raylib.h"
#include "Bullet.h"

class Enemy {
public:
    Bullet bullet;
    std::vector<Bullet> bullets;
    Enemy(int type, Vector2 position);
    void Update(int direction);
    void Draw();
    void Fire();
    int GetType();
    static void UnloadImages();
    Rectangle GetRect();
    static Texture2D enemyTypesImg[3];
    int type;
    Vector2 position;
private:
};

#endif //ENEMY_H
