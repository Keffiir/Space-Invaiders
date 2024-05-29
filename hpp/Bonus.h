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
    int speed;
public:
    bool alive;
    Bonus();
    ~Bonus();
    void Update();
    void Draw();
    void Event();
    void Spawn();
    Rectangle GetRect();
};



#endif //BONUS_H
