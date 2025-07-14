#pragma once

#include "Core/GameState.h"

#if defined(_WIN32) || defined(_WIN64)
    #ifdef LEVERGAME_EXPORTS
        #define LEVERGAME_API __declspec(dllexport)
    #else
        #define LEVERGAME_API __declspec(dllimport)
    #endif
#else
    #define LEVERGAME_API __attribute((visibility("default")))
#endif

extern "C" {
    LEVERGAME_API void SetScreenSize(float width, float height);
    LEVERGAME_API void AddRandomWind(GameState* state);
    LEVERGAME_API void InitGame(GameState* state, float playerMass, float weightMass);
    LEVERGAME_API void UpdateGame(GameState* state, float deltaTime);
    LEVERGAME_API void MovePlayer(GameState* state, float direction, float deltaTime);
}