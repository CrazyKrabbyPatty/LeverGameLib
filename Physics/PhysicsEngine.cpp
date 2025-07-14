#include "PhysicsEngine.h"
#include "../Core/GameConstants.h"
#include <cmath>

namespace PhysicsEngine {

    void UpdateLever(GameState& state, float deltaTime) {
        const float g = GameConstants::GRAVITY;
        const float leverLength = GameConstants::LEVER_LENGTH;

        float tauPlayer = state.player.mass * g * state.player.position * leverLength;
        float tauWeight = state.weight.mass * g * state.weight.position * leverLength;

        float tauEffects = 0.0f;

        for (int i = 0; i < state.activeEffectsCount; ) {
            Effect& effect = state.activeEffects[i];

            tauEffects += effect.strength * effect.position * leverLength;
            effect.duration -= deltaTime;

            if (effect.duration <= 0.0f) {
                // удалить эффект с сохранением порядка
                for (int j = i; j < state.activeEffectsCount - 1; ++j) {
                    state.activeEffects[j] = state.activeEffects[j + 1];
                }
                --state.activeEffectsCount;
            } else {
                ++i;
            }
        }

        float tauTotal = tauPlayer + tauWeight + tauEffects;

        constexpr float momentOfInertia = 1.0f;
        float angularAcceleration = tauTotal / momentOfInertia;

        state.lever.angularVelocity += angularAcceleration * deltaTime;
        state.lever.angle += state.lever.angularVelocity * deltaTime;

        if (std::abs(state.lever.angle) > GameConstants::MAX_ANGLE) {
            state.isGameOver = true;
        }
    }
}
