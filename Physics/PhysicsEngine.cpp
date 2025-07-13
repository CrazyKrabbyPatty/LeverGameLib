#include "PhysicsEngine.h"
#include "../Core/GameConstants.h"
#include <cmath>

namespace PhysicsEngine {

    void UpdateLever(GameState& state, float deltaTime) {
        const float g = GameConstants::GRAVITY;
        const float leverLength = GameConstants::LEVER_LENGTH;

        // Момент от игрока
        float tauPlayer = state.player.mass * g * state.player.position * leverLength;

        // Момент от гири
        float tauWeight = state.weight.mass * g * state.weight.position * leverLength;

        // Моменты от эффектов
        float tauEffects = 0.0f;
        for (auto& effect : state.activeEffects) {
            tauEffects += effect.strength * effect.position * leverLength;
            effect.duration -= deltaTime;
        }
        // Удалить эффекты с истекшей длительностью
        state.activeEffects.erase(
            std::remove_if(state.activeEffects.begin(), state.activeEffects.end(),
                [](const Effect& e) { return e.duration <= 0.0f; }),
            state.activeEffects.end()
        );

        // Суммарный момент
        float tauTotal = tauPlayer + tauWeight + tauEffects;

        // Момент инерции можно считать условно единичным или добавить реальную формулу
        constexpr float momentOfInertia = 1.0f; // упростим

        // Угловое ускорение
        float angularAcceleration = tauTotal / momentOfInertia;

        // Интеграция
        state.lever.angularVelocity += angularAcceleration * deltaTime;
        state.lever.angle += state.lever.angularVelocity * deltaTime;

        // Ограничение максимального угла
        if (std::abs(state.lever.angle) > GameConstants::MAX_ANGLE) {
            state.isGameOver = true;
        }
    }
}
