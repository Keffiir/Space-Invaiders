//
// Created by Иван Никифоров on 19.05.2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Bullet.h"
#include <vector>

/**
 * Класс Player описывает игрока в игре.
 * Отвечает за управление движением, отрисовку, стрельбу и другие действия игрока.
 */

class Player {
private:
    Texture2D image;       // Текстура изображения игрока.
    Vector2 position;      // Позиция игрока на экране.
    int speed;             // Скорость перемещения игрока.

public:
    Player();              // Конструктор.
    ~Player();             // Деструктор.

    void MoveLeft();       // Двигать игрока влево.
    void MoveRight();      // Двигать игрока вправо.
    void Draw();           // Отрисовывает игрока на экране.
    void Update();         // Обновляет состояние игрока.
    void ResetPosition();  // Сбрасывает позицию игрока на начальное положение.

    Vector2 GetCurrentPosition();  // Получает текущую позицию игрока.
    Rectangle GetRect();           // Возвращает прямоугольник, для обработки коллизий.
};

#endif //PLAYER_H
