//
// Created by Иван Никифоров on 27.05.2024.
//

#include "Obstacle.h"

Obstacle::Obstacle(Vector2 position) {
    this->position = position;
}

void Obstacle::Update() {

}

void Obstacle::Draw() {
    DrawRectangle(position.x, position.y, 100, 30, YELLOW);
}

Rectangle Obstacle::GetRect() {
    Rectangle rect;

    rect.x = position.x;
    rect.y = position.y;
    rect.width = 100;
    rect.height = 30;

    return rect;
}




