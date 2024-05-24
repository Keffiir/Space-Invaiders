//
// Created by Иван Никифоров on 19.05.2024.
//

#include "hpp/Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::Draw() {
    player.Draw();
    for(Bullet bullet : bullets) {
        bullet.Draw();
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
    for(int i = 0; i < bullets.size(); i++) {
        bullets[i].Update();
        if(!bullets[i].IsActive()) {
            bullets.erase(bullets.begin() + i);
        }
    }
}




