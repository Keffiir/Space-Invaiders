//
// Created by Иван Никифоров on 19.05.2024.
//

#include "raylib.h"
#include "hpp/Bullet.h"
#include "iostream"

Bullet::Bullet(Vector2 pos, int speed, Color color) {
    this->pos = pos;
    this->speed = speed;
    this->color = color;
    active = true;
}

void Bullet::Draw() {
    DrawRectangle(pos.x, pos.y, 3, 12, color);
}

void Bullet::Update() {
    pos.y += speed;
    if(active) {
        if(pos.y > GetScreenHeight() - 100 || pos.y < 0) {
            active = false;
        }
    }
}

bool Bullet::IsActive() {
    return active;
}

Rectangle Bullet::GetRect() {
    Rectangle rect;
    rect.x = pos.x;
    rect.y = pos.y;
    rect.width = 4;
    rect.height = 12;

    return rect;
}

