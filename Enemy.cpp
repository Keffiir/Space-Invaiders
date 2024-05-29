//
// Created by Иван Никифоров on 24.05.2024.
//

#include "hpp/Enemy.h"
#include "random"

// Инициализация статического массива текстур противников.
Texture2D Enemy::enemyTypesImg[3] = {};

Enemy::Enemy(int type, Vector2 position) : type(type), position(position), bullet({0, 0}, 0, WHITE) {
    // Загрузка текстуры противника в зависимости от типа, если она еще не загружена.
    if (enemyTypesImg[type].id == 0) {
        const char* paths[3] = {
            "images/alien-1.png",
            "images/alien-2.png",
            "images/alien-3.png"
        };
        enemyTypesImg[type] = LoadTexture(paths[type]);
    }
}

void Enemy::Draw() {
    // Отрисовка текстуры противника на его текущей позиции.
    DrawTextureV(enemyTypesImg[type], position, WHITE);
}

int Enemy::GetType() {
    return type;  // Возвращает тип противника.
}

void Enemy::Fire() {
    // Создает новую пулю и добавляет ее в список пуль.
    bullets.push_back(Bullet({position.x, position.y}, 6, BLUE));
}

void Enemy::UnloadImages() {
    // Выгружает все текстуры противников.
    for (int i = 0; i < 3; i++) {
        UnloadTexture(enemyTypesImg[i]);
    }
}

Rectangle Enemy::GetRect() {
    // Возвращает прямоугольник, представляющий границы противника.
    return {position.x, position.y, float(enemyTypesImg[type].width), float(enemyTypesImg[type].height)};
}

void Enemy::Update(int direction) {
    position.x += direction;  // Обновление позиции по горизонтали в зависимости от направления.
}
