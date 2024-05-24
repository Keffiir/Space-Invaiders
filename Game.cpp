//
// Created by Иван Никифоров on 19.05.2024.
//

#include "hpp/Game.h"

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
    for(int row = 0; row < 6; row++) {
        for(int column = 0; column < 11; column++) {
            int enemyType;
            switch (row) {
                case 0:
                case 1:
                    enemyType = 1;
                break;
                case 2:
                case 3:
                    enemyType = 2;
                break;
                case 4:
                case 5:
                    enemyType = 3;
                break;
            }
            float x = 50 + column * 64;
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
                if(CheckCollisionRecs(it -> GetRect(), bullet.GetRect())) {
                    it = enemies.erase(it);
                    bullet.active = false;
                } else {
                    ++it;
                }
            }
        }
    }
}



void Game::MoveEnemies() {

}





