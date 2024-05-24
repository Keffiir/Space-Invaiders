//
// Created by Иван Никифоров on 22.05.2024.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vector>
#include "Block.h"
#include "raylib.h"

class Obstacle {
public:
    Obstacle(Vector2 position);
    void Draw();
    Vector2 position;
    std::vector<Block> blocks;
    static std::vector<std::vector<int>> grid;
private:
};





#endif //OBSTACLE_H
