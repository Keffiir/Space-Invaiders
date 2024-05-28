//
// Created by Иван Никифоров on 27.05.2024.
//

#include "hpp/Obstacle.h"

Obstacle::Obstacle(Vector2 position, Color color) {
    this->position = position;
    this->color = color;
}

void Obstacle::Update() {
    color.a = lives * 20;
}

void Obstacle::Draw() {
    DrawRectangle(position.x, position.y, 75, 30, color);
}

Rectangle Obstacle::GetRect() {
    Rectangle rect;

    rect.x = position.x;
    rect.y = position.y;
    rect.width = 75;
    rect.height = 30;

    return rect;
}




