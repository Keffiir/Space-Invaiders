//
// Created by Иван Никифоров on 19.05.2024.
//

#include "hpp/Player.h"

#include "hpp/Bullet.h"

Player::Player() {
    image = LoadTexture("images/ship.png");
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - 50 - image.height;
    speed = 5;
}

Player::~Player() {
    UnloadTexture(image);
}

void Player::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Player::Update() {
    position.x += speed;
    if(position.x < 0) {
        position.x = 0;
    } else if(position.x > GetScreenWidth() - image.width) {
        position.x = GetScreenWidth() - image.width;
    }
}

void Player::MoveLeft() {
    if(speed > 0) speed = -speed;
}

void Player::MoveRight() {
    if(speed < 0) speed = -speed;
}

Vector2 Player::GetCurrentPosition() {
    return position;
}



