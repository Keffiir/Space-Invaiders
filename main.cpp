//
// Created by Иван Никифоров on 19.05.2024.
//
#include <iostream>
#include "hpp/Bullet.h"
#include "hpp/Player.h"
#include "raylib.h"
#include "hpp/Game.h"
#include "hpp/Obstacle.h"


int main() {
    Color grey = {29, 29, 27, 255};
    int screenWidth = 800;
    int screenHeight = 800;


    InitWindow(screenWidth, screenHeight, "C++ Space Invaiders");
    SetTargetFPS(60);

    Player player;

    Game game;

    GetWorkingDirectory();

    while (!WindowShouldClose()) {

        game.Event();
        game.Update();

        BeginDrawing();

        game.Draw();

        ClearBackground(grey);

        EndDrawing();
    }

    CloseWindow();
}