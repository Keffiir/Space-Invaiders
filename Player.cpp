#include "hpp/Player.h"

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
    DrawTextureV(image, position, WHITE);  // Отрисовка текстуры с текущими координатами.
}

void Player::Update() {
    // Ограничение перемещения игрока в пределах границ экрана.
    if (position.x < 25) {
        position.x = 25;
    } else if (position.x > GetScreenWidth() - image.width - 25) {
        position.x = GetScreenWidth() - image.width - 25;
    }
}

void Player::MoveLeft() {
    position.x -= speed;  // Смещение влево.
}

void Player::MoveRight() {
    position.x += speed;  // Смещение вправо.
}

Vector2 Player::GetCurrentPosition() {
    return position;  // Возвращает текущую позицию игрока.
}

Rectangle Player::GetRect() {
    // Возвращает прямоугольник, представляющий границы игрока.
    return {position.x, position.y, float(image.width), float(image.height)};
}

void Player::ResetPosition() {
    position.x = (GetScreenWidth() - image.width) / 2;  // Сброс позиции игрока.
}