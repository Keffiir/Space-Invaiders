#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

/**
 * Класс Bullet представляет снаряд в игре.
 * Отвечает за отрисовку, обновление состояния и проверку активности снаряда.
 */

class Bullet {
public:
    Bullet(Vector2 position, int speed, Color color);  // Конструктор снаряда.
    void Update();  // Обновление положения снаряда.
    void Draw();    // Отрисовка снаряда.
    bool IsActive();  // Проверка, активен ли снаряд.
    Rectangle GetRect();  // Получение прямоугольника, для обработки коллизий.

    bool active;   // Флаг активности снаряда.
    int speed;     // Скорость движения снаряда.
    Color color;   // Цвет снаряда.

private:
    Vector2 pos;   // Текущая позиция снаряда.
};

#endif // BULLET_H
