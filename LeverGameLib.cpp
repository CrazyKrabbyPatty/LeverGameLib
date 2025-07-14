#include "LeverGameLib.h"
#include "Effects/WindEffect/WindEffect.h"
#include "Core/GameConstants.h"
#include "Core/GameState.h"
#include "Physics/PhysicsEngine.h"

extern "C" {
    LEVERGAME_API void SetScreenSize(float width, float height) {
        GameConstants::ScreenWidth = width;
        GameConstants::ScreenHeight = height;
    }

    LEVERGAME_API void AddRandomWind(GameState* state) {
        auto wind = Effects::WindEffect::CreateRandom();
        wind.Apply(*state);
    }

    LEVERGAME_API void InitGame(GameState* state, float playerMass, float weightMass) {
        state->player.mass = playerMass;
        state->weight.mass = weightMass;
        state->isGameOver = false;
        state->activeEffectsCount = 0;
        state->lever.angle = 0.0f;
        state->lever.angularVelocity = 0.0f;
    }

    LEVERGAME_API void UpdateGame(GameState* state, float deltaTime) {
        if (state->isGameOver) return;

        PhysicsEngine::UpdateLever(*state, deltaTime);

        // Можно добавить: начисление очков, проверка условий победы и т.п.
    }

    LEVERGAME_API void MovePlayer(GameState* state, float direction, float deltaTime) {
        if (state->isGameOver) return;

        constexpr float playerSpeed = 2.0f;       // Базовая скорость управления (ускорение)
        constexpr float gravityFactor = 5.0f;     // Влияние наклона на ускорение
        constexpr float friction = 0.9f;          // Трение
        constexpr float maxVelocity = 2.0f;       // Максимальная скорость игрока

        // 1. Управление пользователем (ускорение)
        state->player.velocity += direction * playerSpeed * deltaTime;

        // 2. Гравитационное ускорение из-за наклона рычага
        float gravityAcceleration = -std::sin(state->lever.angle) * gravityFactor;
        state->player.velocity += gravityAcceleration * deltaTime;

        // 3. Применить трение
        state->player.velocity *= friction;

        // 4. Ограничить максимальную скорость
        if (state->player.velocity > maxVelocity) state->player.velocity = maxVelocity;
        if (state->player.velocity < -maxVelocity) state->player.velocity = -maxVelocity;

        // 5. Перемещение
        state->player.position += state->player.velocity * deltaTime;

        // 6. Ограничить позицию
        if (state->player.position > 1.0f) {
            state->player.position = 1.0f;
            state->player.velocity = 0.0f;
        }
        if (state->player.position < -1.0f) {
            state->player.position = -1.0f;
            state->player.velocity = 0.0f;
        }
    }

    LEVERGAME_API int GetActiveEffectsCount(GameState* state) {
        return state->activeEffectsCount;
    }

}