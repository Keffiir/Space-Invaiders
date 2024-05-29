//
// Created by Иван Никифоров on 19.05.2024.
//

#include "raylib.h"
#include "hpp/Bullet.h"

Bullet::Bullet(Vector2 position, int speed, Color color) {
    this->pos = position;
    this->speed = speed;
    this->color = color;
    active = true;
}

void Bullet::Draw() {
    // Отрисовка снаряда как прямоугольника.
    DrawRectangle(pos.x, pos.y, 4, 12, color);
}

void Bullet::Update() {
    // Обновление позиции снаряда.
    pos.y += speed;

    // Проверка на выход снаряда за пределы игровой зоны.
    if (active && (pos.y > GetScreenHeight() - 100 || pos.y < 0)) {
        active = false;
    }
}

bool Bullet::IsActive() {
    return active;  // Возвращает статус активности снаряда.
}

Rectangle Bullet::GetRect() {
    // Создание и возвращение прямоугольника, описывающего снаряд.
    Rectangle rect = {pos.x, pos.y, 4, 12};
    return rect;
}
