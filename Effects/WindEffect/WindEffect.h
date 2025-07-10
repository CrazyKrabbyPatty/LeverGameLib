//
// Created by CrazyKrabbyPatty on 10.07.2025.
//

#ifndef WINDEFFECT_H
#define WINDEFFECT_H

#include "../../Core/GameState.h"
#include <random>

namespace Effects {

    class WindEffect {
    private:
        // Приватные поля (инкапсуляция)
        float strength_;    // Сила ветра
        float position_;    // Позиция на рычаге (-1.0 до 1.0)
        float width_;       // Ширина потока
        float duration_;    // Длительность эффекта
        int direction_;     // Направление (-1 влево, 1 вправо)

        // Генератор случайных чисел
        static std::mt19937 randomGenerator_;

    public:
        // Конструктор с параметрами
        WindEffect(float strength, float position, float width, float duration, int direction);

        // Конструктор для случайного ветра
        static WindEffect CreateRandom();

        // Применить эффект к состоянию игры
        void Apply(GameState& state) const;

        // Геттеры (опционально)
        float GetStrength() const { return strength_; }
        float GetPosition() const { return position_; }
        int GetDirection() const { return direction_; }
    };

} // namespace Effects



#endif //WINDEFFECT_H
