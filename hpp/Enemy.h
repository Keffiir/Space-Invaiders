//
// Created by Иван Никифоров on 24.05.2024.
//

#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "raylib.h"
#include "Bullet.h"

/**
 * Класс Enemy описывает противника в игре.
 * Управляет отрисовкой, обновлением состояния, стрельбой и другими действиями противника.
 */
class Enemy {
public:
    Enemy(int type, Vector2 position);  // Конструктор принимает тип и начальную позицию.
    void Update(int direction);         // Обновляет позицию противника.
    void Draw();                        // Отрисовывает противника.
    void Fire();                        // Выпускает пули.
    int GetType();                      // Возвращает тип противника.
    Rectangle GetRect();                // Возвращает прямоугольник, описывающий противника.

    static void UnloadImages();         // Выгружает изображения противников.
    static Texture2D enemyTypesImg[3];  // Статический массив текстур для разных типов противников.
    int type;                           // Тип противника.
    Vector2 position;                   // Текущая позиция противника на экране.

private:
    Bullet bullet;                  // Пуля противника.
    std::vector<Bullet> bullets;    // Вектор пуль, выпущенных противником.
};

#endif //ENEMY_H
