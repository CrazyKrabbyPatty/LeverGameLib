#include "LeverGameLib.h"
#include "Effects/WindEffect/WindEffect.h"
#include "Core/GameConstants.h"

extern "C" {
    LEVERGAME_API void SetScreenSize(float width, float height) {
        GameConstants::ScreenWidth = width;
        GameConstants::ScreenHeight = height;
    }

    LEVERGAME_API void AddRandomWind(GameState* state) {
        auto wind = Effects::WindEffect::CreateRandom();
        wind.Apply(*state);
    }

//    LEVERGAME_API void InitGame(GameState* state, float playerMass, float weightMass) {
//        // Implementation here
//    }
//
//    LEVERGAME_API void UpdateGame(GameState* state, float deltaTime) {
//        // Implementation here
//    }
}