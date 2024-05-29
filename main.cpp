//
// Created by Иван Никифоров on 19.05.2024.
//
#include <iostream>
#include <string>
#include "hpp/Bullet.h"
#include "hpp/Player.h"
#include "raylib.h"
#include "hpp/Game.h"
#include "hpp/Obstacle.h"
#include "hpp/Bonus.h"

void DrawUI(Game& game, Texture2D& playerTexture) {
    Color white = WHITE;
    float x = 50.0;

    DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18f, 20, 2, white);
    DrawLineEx({25, 710}, {775, 710}, 3, white);

    if (game.run) {
        DrawTextEx(GetFontDefault(), "LEVEL 01", {570, 740}, 34, 2, white);
    } else if (game.win && !game.run) {
        DrawTextEx(GetFontDefault(), "YOU WIN!", {350, 400}, 34, 2, white);
        DrawTextEx(GetFontDefault(), "PRESS R TO PLAY", {270, 450}, 34, 2, white);
    } else if (!game.win && !game.run) {
        DrawTextEx(GetFontDefault(), "GAME OVER", {300, 740}, 34, 2, white);
    }

    for (float i = 0; i < game.playerLives; i++) {
        DrawTextureV(playerTexture, {x, 720}, white);
        x += 50;
    }

    DrawTextEx(GetFontDefault(), "SCORE:", {50, 15}, 34, 2, white);
    std::string scoreText = std::to_string(game.playerScore);
    DrawTextEx(GetFontDefault(), scoreText.c_str(), {175, 15}, 34, 2, white);
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;
    const Color grey = {29, 29, 27, 255};

    InitWindow(screenWidth, screenHeight, "C++ Space Invaders");
    SetTargetFPS(60);

    Texture2D playerTexture = LoadTexture("images/ship.png");
    Player player;
    Game game;

    while (!WindowShouldClose()) {
        game.Event();
        game.Update();

        BeginDrawing();
        ClearBackground(grey);

        DrawUI(game, playerTexture);
        game.Draw();

        EndDrawing();
    }

    UnloadTexture(playerTexture);
    CloseWindow();
    return 0;
}
