#pragma once

struct Player {
    float position = 0.0f;  // Позиция на рычаге [-1.0, 1.0]
    float velocity = 0.0f;  // Скорость передвижения по рычагу
    float mass = 70.0f;     // Масса игрока (кг)
    bool isAlive = true;
};