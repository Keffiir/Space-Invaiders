//
// Created by Иван Никифоров on 19.05.2024.
//

#include "hpp/Game.h"
#include "iostream"
#include "random"

Game::Game() {
    enemies = CreateEnemies();
    obstacles = CreateObstacles();
    enemiesDirection = 1;
    timeLastEnemyShoot = 0.0f;
    run = true;
}

Game::~Game() {

}

void Game::Draw() {
    player.Draw();
    for(auto& bullet : bullets) {
        bullet.Draw();
    }

    for(auto& enemy: enemies) {
        enemy.Draw();
    }

    for(auto& obstacle : obstacles) {
        obstacle.Draw();
    }
}

void Game::Event() {
    if(run) {
        if(IsKeyDown(KEY_LEFT)) {
            player.MoveLeft();
        } else if(IsKeyDown(KEY_RIGHT)) {
            player.MoveRight();
        } else if(IsKeyDown(KEY_SPACE)) {
            if(GetTime() - lastShotTime >= shotInterval) {
                bullets.push_back(Bullet({player.GetCurrentPosition().x + 25, player.GetCurrentPosition().y}, -10, RED));
                lastShotTime = GetTime();
            }
        }
    } else {
        if(IsKeyDown(KEY_ENTER)) {
            ResetGame();
            InitGame();
        }
    }

    if(playerLives == 0) {
        GameOver();
    } else if(playerScore == 11000) {
        GameWin();
    }
}

void Game::Update() {

    if(run) {

        player.Update();

        for(auto& obstacle : obstacles) {
            obstacle.Update();
        }

        MoveEnemies();

        EnemyFire();

        CheckForCollisions();

        for(int i = 0; i < bullets.size(); i++) {
            bullets[i].Update();
            if(!bullets[i].IsActive()) {
                bullets.erase(bullets.begin() + i);
            }
        }
    }
}

// Функция создания врагов

std::vector<Enemy> Game::CreateEnemies() {
    std::vector<Enemy> enemies;
    int enemyType = 0;
    for(int row = 0; row < 5; row++) {
        for(int column = 0; column < 10; column++) {
            if(row == 2 || row == 3) {
                enemyType = 1;
            } else if(row == 4) {
                enemyType = 2;
            }
            float x = column * 64;
            float y = row * 64 + 50;
            enemies.push_back(Enemy(enemyType, {x + 50, y}));
        }
    }
    return enemies;
}

// Функция которая создает щиты

std::vector<Obstacle> Game::CreateObstacles() {
    std::vector<Obstacle> obstacles;
    obstacles.push_back(Obstacle({100,550}, GRAY));
    obstacles.push_back(Obstacle({350,550}, GRAY));
    obstacles.push_back(Obstacle({600,550}, GRAY));
    return obstacles;
}


// Функция проверки коллизий

void Game::CheckForCollisions() {
    for(auto& bullet: bullets) {

        // Проверка коллизий с щитами
        auto it = obstacles.begin();
        while(it != obstacles.end()){
            if(CheckCollisionRecs(bullet.GetRect(), it->GetRect())) {

                if(it->lives <= 1) {
                    obstacles.erase(it);
                }

                bullet.active = false;
                // std::cout << "Obstacle collision";
                it->lives--;
                break;

            } else {
                it++;
            }
        }

        // Пули от игрока
        if(bullet.speed < 0) {

            // Коллизии для пуль игрока и врагов
            auto it = enemies.begin();
            while(it != enemies.end()){
                if(CheckCollisionRecs(it->GetRect(), bullet.GetRect())) {

                    // Очки за разные типы пришельцев
                    if(it->GetType() == 0) {
                        playerScore += 300;
                    } else if(it->GetType() == 1) {
                        playerScore += 200;
                    } else {
                        playerScore += 100;
                    }

                    it = enemies.erase(it);
                    std::cout << "Collision detected: Bullet at (" << bullet.GetRect().x << ", " << bullet.GetRect().y << ") and Enemy at (" << it->GetRect().x << ", " << it->GetRect().y << ")\n";
                    std::cout << playerScore;
                    bullet.active = false;
                    break;
                } else {
                    ++it;
                }
            }
        }

        // Пули от врагов
        else {

            // Коллизии для пуль врагов и игрока
            if(CheckCollisionRecs(bullet.GetRect(), player.GetRect())) {
                playerLives--;
                bullet.active = false;
                std::cout << "Player lives: " << playerLives << " ";
            }
        }
    }
}

int Game::GameOver() {
    run = false;
    return playerScore;
}

// Функция движения врагов

void Game::MoveEnemies() {
    bool changeDirection = false;

    for(auto& enemy : enemies) {
        enemy.Update(enemiesDirection);
        if (enemy.GetRect().x <= 25 || enemy.GetRect().x + enemy.GetRect().width >= GetScreenWidth() - 25) {
            changeDirection = true;

        }
    }

    if (changeDirection) {
        enemiesDirection = -enemiesDirection;
        for(auto& enemy : enemies) {
            enemy.Update(enemiesDirection);
        }
        MoveEnemiesDown();
    }
}

void Game::EnemyFire() {
    double currentTime = GetTime();

    if(currentTime - timeLastEnemyShoot >= enemyShootInterval && !enemies.empty()) {
        int randomIndex = GetRandomValue(0, enemies.size() - 1);
        Enemy& enemy = enemies[randomIndex];
        if(enemy.type == 0) {
            bullets.push_back(Bullet({enemy.position.x + 25, enemy.position.y}, 8, PURPLE));
            timeLastEnemyShoot = GetTime();
        } else if(enemy.type == 1) {
            bullets.push_back(Bullet({enemy.position.x + 25, enemy.position.y}, 6, GREEN));
            timeLastEnemyShoot = GetTime();
        } else if(enemy.type == 2) {
            bullets.push_back(Bullet({enemy.position.x + 25, enemy.position.y}, 4, YELLOW));
            timeLastEnemyShoot = GetTime();
        }
    }
}

// Функция сдвига врагов вниз

void Game::MoveEnemiesDown() {
    for(auto& enemy : enemies) {
        enemy.position.y += 20;
    }
}

int Game::GameWin() {
    win = true;
    run = false;
}


void Game::ResetGame() {
    player.ResetPosition();
    bullets.clear();
    enemies.clear();
    obstacles.clear();
    win = false;
}

void Game::InitGame() {
    playerLives = 3;
    playerScore = 0;
    enemies = CreateEnemies();
    obstacles = CreateObstacles();
    enemiesDirection = 1;
    run = true;
}




