//
// Created by Иван Никифоров on 19.05.2024.
//

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Bullet.h"
#include <vector>
#include "Enemy.h"
#include "Obstacle.h"


class Game {
private:
    Player player;
    std::vector<Obstacle> obstacles;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<Enemy> CreateEnemies();
    std::vector<Obstacle> CreateObstacles();
    int playerLives = 3;
    int playerScore = 0;
    float shotInterval = 0.25f;
    float lastShotTime = 0.0f;
    void MoveEnemies();
    void MoveEnemiesDown();
    int enemiesDirection;
    int GameOver();
    void CheckForCollisions();
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void Event();
};



#endif //GAME_H
