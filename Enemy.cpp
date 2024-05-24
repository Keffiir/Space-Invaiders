//
// Created by Иван Никифоров on 24.05.2024.
//

#include "hpp/Enemy.h"

Texture2D Enemy::enemyTypesImg[3] = {};

Enemy::Enemy(int type, Vector2 position) {

    this->type = type;
    this->position = position;

    if(enemyTypesImg[type -1].id == 0) {

        switch (type) {
            case 1:
                enemyTypesImg[0] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/alien-1.png");
            break;
            case 2:
                enemyTypesImg[1] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/alien-2.png");
            break;
            case 3:
                enemyTypesImg[2] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/alien-3.png");
            break;
            default:
                enemyTypesImg[0] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/alien-1.png");
            break;
        }
    }
}

void Enemy::Draw() {
    DrawTextureV(enemyTypesImg[type - 1], position, WHITE);
}

int Enemy::GetType() {
    return type;
}

void Enemy::UnloadImages() {
    for(int i = 0; i < 4; i++) {
        UnloadTexture(enemyTypesImg[i]);
    }
}

Rectangle Enemy::getRect() {
    return {position.x, position.y,
    float(enemyTypesImg[type - 1].width),
    float(enemyTypesImg[type - 1].height)
    };
}

void Enemy::Update(int direction) {
    position.x += direction;
}