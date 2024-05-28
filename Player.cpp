//
// Created by Иван Никифоров on 19.05.2024.
//

#include "hpp/Player.h"

#include "hpp/Bullet.h"

Player::Player() {
    image = LoadTexture("images/ship.png");
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - 100 - image.height;
    speed = 5;
}

Player::~Player() {
    UnloadTexture(image);
}

void Player::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Player::Update() {
    if(position.x < 25) {
        position.x = 25;
    } else if(position.x > GetScreenWidth() - image.width - 25) {
        position.x = GetScreenWidth() - image.width - 25;
    }
}

void Player::MoveLeft() {
    position.x -= speed;
}

void Player::MoveRight() {
    position.x += speed;
}

Vector2 Player::GetCurrentPosition() {
    return position;
}

Rectangle Player::GetRect() {
    return {position.x, position.y, float(image.width), float(image.height)};
}

void Player::ResetPosition() {
    position.x = (GetScreenWidth() - image.width) / 2;
}




