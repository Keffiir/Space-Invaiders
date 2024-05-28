//
// Created by Иван Никифоров on 27.05.2024.
//

#include "hpp/Bonus.h"

Texture2D Bonus::bonusTypesImg[1] = {};

Bonus::Bonus(int type, Vector2 position) {

    this->type = type;
    this->position = position;

    if(bonusTypesImg[type].id == 0) {

        switch (type) {
            case 0:
                bonusTypesImg[0] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/bonus.png");
            break;
            case 1:
                bonusTypesImg[1] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/bonus.png");
            break;
            default:
                bonusTypesImg[0] = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/bonus.png");
            break;
        }
    }
}

void Bonus::Event() {

}

void Bonus::Update() {
    position.x += 1;
}

void Bonus::Draw() {
    DrawTextureV(texture, position, WHITE);
}
