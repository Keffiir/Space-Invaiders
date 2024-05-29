//
// Created by Иван Никифоров on 19.05.2024.
//

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Obstacle.h"
#include "Bonus.h"
#include <vector>

/**
 * Класс Game управляет основными элементами и логикой игры.
 * Включает в себя управление игроком, врагами, препятствиями и обработку событий.
 */

class Game {
private:
    Player player;                      // Объект игрока.
    Bonus bonus;
    std::vector<Obstacle> obstacles;    // Вектор препятствий.
    std::vector<Bullet> bullets;        // Вектор пуль.
    std::vector<Enemy> enemies;         // Вектор врагов.
    float shotInterval = 0.25f;         // Интервал между выстрелами.
    float lastShotTime = 0.0f;          // Время последнего выстрела.
    int enemiesDirection;               // Направление движения врагов.
    float enemyShootInterval = 0.2f;    // Интервал стрельбы врагов.
    float timeLastEnemyShoot;           // Время последнего выстрела врага.
    float bonusSpawnInterval;
    float timeLastSpawn;
    float bonusModeStartTime = 0.0f;
    float bonusModeDuration = 3.0f;
    bool laserModeEnabled = false;

    std::vector<Enemy> CreateEnemies();         // Создает вектор врагов.
    std::vector<Obstacle> CreateObstacles();    // Создает вектор препятствий.
    void MoveEnemies();                         // Двигает врагов.
    void MoveEnemiesDown();                     // Двигает врагов вниз.
    int GameOver();                             // Завершает игру.
    int GameWin();                              // Победа
    void InitGame();                            // Инициализирует игру.
    void ResetGame();                           // Сбрасывает игру.
    void CheckForCollisions();                  // Проверяет на коллизии.
    void EnemyFire();                           // Стрельба врагов.
    void EnableLaserMode();
    void UpdateLaserMode();

public:
    bool run;                                   // Состояние игры: запущена или остановлена.
    bool win;
    int playerLives = 3;                        // Жизни игрока.
    int playerScore;                            // Счет игрока.

    Game();                                     // Конструктор.
    void Draw();                                // Отрисовывает элементы игры.
    void Update();                              // Обновляет состояние игры.
    void Event();                               // Обрабатывает ввод пользователя.
};

#endif //GAME_H
