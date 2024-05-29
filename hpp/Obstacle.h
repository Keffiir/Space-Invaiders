//
// Created by Иван Никифоров on 27.05.2024.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

/**
 * @brief Класс Obstacle представляет препятствие в игре.
 * Отвечает за отображение, обновление и управление жизненным циклом препятствия.
 */

class Obstacle {
public:
    Obstacle(Vector2 position, Color color);  // Конструктор препятствия.
    void Update();  // Обновляет состояние препятствия.
    void Draw();    // Отрисовывает препятствие.
    Rectangle GetRect();  // Возвращает прямоугольник, для коллизий.
    bool IsActive();  // Проверяет, активно ли препятствие.
    int lives = 8;         // Количество жизней препятствия.

private:
    Vector2 position;  // Позиция препятствия на экране.
    Color color;       // Цвет препятствия.
};

#endif // OBSTACLE_H

