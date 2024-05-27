//
// Created by Иван Никифоров on 24.05.2024.
//

#include "hpp/Enemy.h"
#include "random"

Texture2D Enemy::enemyTypesImg[3] = {};

Enemy::Enemy(int type, Vector2 position) : bullet({0, 0}, 0, WHITE), type(type), position(position) {

    this->type = type;
    this->position = position;

    if(enemyTypesImg[type].id == 0) {

        switch (type) {
            case 0:
                enemyTypesImg[0] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/alien-1.png");
            break;
            case 1:
                enemyTypesImg[1] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/alien-2.png");
            break;
            case 2:
                enemyTypesImg[2] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/alien-3.png");
            break;
            default:
                enemyTypesImg[0] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/alien-1.png");
            break;
        }
    }
}

void Enemy::Draw() {
    DrawTextureV(enemyTypesImg[type], position, WHITE);
}

int Enemy::GetType() {
    return type;
}

void Enemy::Fire() {
    bullets.push_back(Bullet({position.x, position.y}, 6, BLUE));
}

void Enemy::UnloadImages() {
    for(int i = 0; i < 3; i++) {
        UnloadTexture(enemyTypesImg[i]);
    }
}

Rectangle Enemy::GetRect() {
    return {position.x, position.y,
    float(enemyTypesImg[type].width),
    float(enemyTypesImg[type].height)
    };
}

void Enemy::Update(int direction) {

    position.x += direction;

    // Удаление неактивных пуль
    // bullets.erase(
    //     std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return !b.IsActive(); }),
    //     bullets.end()
    // );
}

