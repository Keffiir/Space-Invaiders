//
// Created by Иван Никифоров on 27.05.2024.
//

#include "hpp/Obstacle.h"

// Инициализация щита с заданной позицией и цветом.
Obstacle::Obstacle(Vector2 position, Color color) {
    this->position = position;
    this->color = color;
}

void Obstacle::Update() {
    // Обновление прозрачности цвета в зависимости от количества жизней.
    color.a = lives * 20;
}

void Obstacle::Draw() {
    // Отрисовка щита
    DrawRectangle(position.x, position.y, 75, 30, color);
}

Rectangle Obstacle::GetRect() {
    // Возвращение хитбокса.
    return {position.x, position.y, 75, 30};
}




