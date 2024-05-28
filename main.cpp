//
// Created by Иван Никифоров on 19.05.2024.
//
#include <iostream>
#include "hpp/Bullet.h"
#include "hpp/Player.h"
#include "raylib.h"
#include "hpp/Game.h"
#include "hpp/Obstacle.h"
#include "hpp/Bonus.h"
#include "string"


int main() {

    Color grey = {29, 29, 27, 255};
    int screenWidth = 800;
    int screenHeight = 800;

    // Font font = LoadFont("Font/Keleti-Regular.ttf");

    InitWindow(screenWidth, screenHeight, "C++ Space Invaiders");
    SetTargetFPS(60);

    Texture2D playerTexture = LoadTexture("/Users/nikiforovivan/CLionProjects/space-invaiders/images/ship.png");

    Player player;

    Bonus bonus(0, {500, 500});

    Game game;

    GetWorkingDirectory();

    while (!WindowShouldClose()) {

        game.Event();
        game.Update();

        BeginDrawing();

        DrawRectangleRoundedLines({10,10,780,780}, 0.18f, 20, 2, WHITE);
        DrawLineEx({25, 710}, {775, 710}, 3, WHITE);
        if(game.run) {
            DrawTextEx(GetFontDefault(), "LEVEL 01", {570, 740}, 34, 2, WHITE);
        } else {
            DrawTextEx(GetFontDefault(), "GAME OVER", {300, 740}, 34, 2, WHITE);
        }

        float x = 50.0;
        for(float i = 0; i < game.playerLives; i++) {
            DrawTextureV(playerTexture, {x, 720}, WHITE);
            x += 50;
        }

        DrawTextEx(GetFontDefault(), "SCORE:", {50, 15}, 34, 2, WHITE);
        std::string numberText = std::to_string(game.playerScore);

        DrawTextEx(GetFontDefault(), numberText.c_str(), {175, 15}, 34, 2, WHITE);
        DrawTextEx(GetFontDefault(), "LEVEL 01", {570, 740}, 34, 2, WHITE);


        game.Draw();

        ClearBackground(grey);

        EndDrawing();
    }

    CloseWindow();
}