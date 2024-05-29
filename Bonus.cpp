//
// Created by Иван Никифоров on 27.05.2024.
//

#include "hpp/Bonus.h"

Bonus::Bonus() {
    texture = LoadTexture("images/bonus.png");
    alive = false;
}

Bonus::~Bonus() {
    UnloadTexture(texture);
}

void Bonus::Spawn() {
    position.y = 90;
    int side = GetRandomValue(0, 1);

    if(side == 0) {
        position.x = 0;
        speed = 2;
    } else {
        position.x = GetScreenWidth() - texture.width;
        speed = -2;
    }
    alive = true;
}

void Bonus::Update() {
    if(alive) {
        position.x += speed;
        if(position.x > GetScreenWidth() - texture.width || position.x < 0) {
            alive = false;
        }
    }
}


void Bonus::Draw() {
    if(alive) {
        DrawTextureV(texture, position, WHITE);
    }
}

Rectangle Bonus::GetRect() {
    return {position.x, position.y, float(texture.width), float(texture.height)};
}

