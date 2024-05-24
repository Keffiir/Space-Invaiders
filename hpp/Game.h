//
// Created by Иван Никифоров on 19.05.2024.
//

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Bullet.h"
#include <vector>
#include "Enemy.h"


class Game {
private:
    Player player;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<Enemy> CreateEnemies();
    void MoveEnemies();
    int EnemiesDirection();
    void CheckForCollisions();
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void Event();
};



#endif //GAME_H
