#pragma once

#include "Core/GameState.h"

#ifdef LEVERGAME_EXPORTS  // Определяется при сборке DLL
    #define LEVERGAME_API __declspec(dllexport)
#else
    #define LEVERGAME_API __declspec(dllimport)
#endif

extern "C" {
    LEVERGAME_API void SetScreenSize(float width, float height);
    LEVERGAME_API void AddRandomWind(GameState* state);
    LEVERGAME_API void InitGame(GameState* state, float playerMass, float weightMass);
    LEVERGAME_API void UpdateGame(GameState* state, float deltaTime);
}