//
// Created by Иван Никифоров on 22.05.2024.
//

#include "hpp/Block.h"

#include "hpp/Block.h"

Block::Block(Vector2 position) {
    this -> position = position;
}

void Block::Draw() {
    DrawRectangle(position.x, position.y, 5, 5, {255, 0, 0, 255});
}