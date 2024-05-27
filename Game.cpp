//
// Created by Иван Никифоров on 19.05.2024.
//

#include "hpp/Game.h"
#include "iostream"
#include "random"
#include "iostream"

Game::Game() {
    enemies = CreateEnemies();
    enemiesDirection = 1;
}

Game::~Game() {

}

void Game::Draw() {
    player.Draw();
    for(Bullet bullet : bullets) {
        bullet.Draw();
    }

    for(Enemy enemy: enemies) {
        enemy.Draw();
    }
}

void Game::Event() {
    if(IsKeyDown(KEY_LEFT)) {
        player.MoveLeft();
    } else if(IsKeyDown(KEY_RIGHT)) {
        player.MoveRight();
    } else if(IsKeyDown(KEY_SPACE)) {
        if(GetTime() - lastShotTime >= shotInterval) {
            bullets.push_back(Bullet({player.GetCurrentPosition().x + 25, player.GetCurrentPosition().y}, -5, RED));
            lastShotTime = GetTime();
        }
    }

    if(playerLives == 0) {
        // Game over
    }
}

void Game::Update() {
    player.Update();

    MoveEnemies();

    for(Enemy enemy : enemies) {
        if((rand() % 500) < 1 && bullets.size() < 20) {
            if(enemy.type == 0) {
                bullets.push_back(Bullet({enemy.position.x + 25, enemy.position.y}, 6, PURPLE));
            } else if(enemy.type == 1) {
                bullets.push_back(Bullet({enemy.position.x + 25, enemy.position.y}, 5, GREEN));
            } else if(enemy.type == 2) {
                bullets.push_back(Bullet({enemy.position.x + 25, enemy.position.y}, 4, YELLOW));
            }
        }
    }

    CheckForCollisions();
    for(int i = 0; i < bullets.size(); i++) {
        bullets[i].Update();
        if(!bullets[i].IsActive()) {
            bullets.erase(bullets.begin() + i);
        }
    }
}

std::vector<Enemy> Game::CreateEnemies() {
    std::vector<Enemy> enemies;
    int enemyType = 0;
    for(int row = 0; row < 6; row++) {
        for(int column = 0; column < 11; column++) {
            if(row == 2 || row == 3) {
                enemyType = 1;
            } else if(row == 4 || row == 5) {
                enemyType = 2;
            }
            float x = column * 64;
            float y = row * 64;
            enemies.push_back(Enemy(enemyType, {x, y}));
        }
    }
    return enemies;
}

void Game::CheckForCollisions() {
    for(auto& bullet: bullets) {

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
    return playerScore;
}




void Game::MoveEnemies() {
    bool changeDirection = false;

    for(auto& enemy : enemies) {
        enemy.Update(enemiesDirection);
        if (enemy.GetRect().x <= 0 || enemy.GetRect().x + enemy.GetRect().width >= GetScreenWidth()) {
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

void Game::MoveEnemiesDown() {
    for(auto& enemy : enemies) {
        enemy.position.y += 5;
    }
}




