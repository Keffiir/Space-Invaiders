//
// Created by Иван Никифоров on 19.05.2024.
//

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Bullet.h"
#include "Obstacle.h"
#include <vector>


class Game {
private:
    Player player;
    std::vector<Bullet> bullets;
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void Event();
};



#endif //GAME_H
