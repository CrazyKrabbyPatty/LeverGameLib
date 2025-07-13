#pragma once

#include <vector>

// Типы воздействий
enum class EffectType {
    None,
    Wind,
    Stone,
    Ability
};

// Параметры воздействия
struct Effect {
    EffectType type;
    float strength;  // Сила воздействия (ветра/камня)
    float position;  // Позиция на рычаге [-1.0, 1.0]
    float duration; // Длительность в секундах
};

// Параметры игрока
struct Player {
    float position = 0.0f;  // Позиция на рычаге [-1.0, 1.0]
    float velocity = 0.0f;
    float mass = 70.0f;     // Масса игрока (кг)
    bool isAlive = true;
};

// Параметры гири
struct Weight {
    float position = 0.0f;  // Позиция на рычаге
    float mass = 50.0f;     // Масса гири (кг)
    bool isActive = true;   // Доступна ли игроку
};

// Параметры рычага
struct Lever {
    float angle = 0.0f;           // Текущий угол наклона (радианы)
    float angularVelocity = 0.0f; // Скорость изменения угла
    float length = 2.0f;          // Длина рычага (условные единицы)
};

// Полное состояние игры
struct GameState {
    Lever lever;
    Player player;
    Weight weight;
    std::vector<Effect> activeEffects;
    int score = 0;
    bool isGameOver = false;
};

