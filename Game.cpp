//
// Created by Иван Никифоров on 19.05.2024.
//

#include "hpp/Game.h"
#include "iostream"

Game::Game() {
    enemies = CreateEnemies();
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
    if(IsKeyPressed(KEY_LEFT)) {
        player.MoveLeft();
    } else if(IsKeyPressed(KEY_RIGHT)) {
        player.MoveRight();
    } else if(IsKeyPressed(KEY_SPACE)) {
        bullets.push_back(Bullet({player.GetCurrentPosition().x + 25, player.GetCurrentPosition().y}, -5));
    }
}

void Game::Update() {
    player.Update();
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
        if(bullet.speed < 0) {
            auto it = enemies.begin();
            while(it != enemies.end()){
                if(CheckCollisionRecs(it->GetRect(), bullet.GetRect())) {
                    it = enemies.erase(it);
                    std::cout << "Collision detected: Bullet at (" << bullet.GetRect().x << ", " << bullet.GetRect().y << ") and Enemy at (" << it->GetRect().x << ", " << it->GetRect().y << ")\n";
                    bullet.active = false;
                    break;
                } else {
                    ++it;
                }
            }
        }
    }
}



void Game::MoveEnemies() {

}





