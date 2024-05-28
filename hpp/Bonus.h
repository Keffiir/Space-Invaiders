//
// Created by Иван Никифоров on 27.05.2024.
//

#ifndef BONUS_H
#define BONUS_H
#include "raylib.h"


class Bonus {
private:
    int type;
    Texture2D texture;
    Vector2 position;
    static Texture2D bonusTypesImg[1];
public:
    Bonus(int type, Vector2 position);
    void Update();
    void Draw();
    void Event();
    Rectangle GetRect();
};



#endif //BONUS_H
