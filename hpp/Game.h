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
#include "Bonus.h"


class Game {
private:
    Player player;
    // Bonus bonus;
    std::vector<Obstacle> obstacles;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<Enemy> CreateEnemies();
    std::vector<Obstacle> CreateObstacles();
    float shotInterval = 0.25f;
    float lastShotTime = 0.0f;
    void MoveEnemies();
    void MoveEnemiesDown();
    int enemiesDirection;
    constexpr static float enemyShootInterval = 0.2;
    float timeLastEnemyShoot;
    int GameOver();
    void InitGame();
    void ResetGame();
    void CheckForCollisions();
    void EnemyFire();
public:
    int playerLives = 3;
    bool run;
    int playerScore;
    Game();
    ~Game();
    void Draw();
    void Update();
    void Event();
};

#endif //GAME_H
