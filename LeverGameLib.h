// LeverGameLib.h
#pragma once

#include "Core/GameState.h"
#include "Core/GameConstants.h"

// Определяем макрос для экспорта/импорта
#ifdef _WIN32
    #ifdef LEVERGAME_EXPORTS  // Определяется при сборке DLL
        #define LEVERGAME_API __declspec(dllexport)
    #else
        #define LEVERGAME_API __declspec(dllimport)
    #endif
#else
    #define LEVERGAME_API  // Пустой макрос для Linux/macOS
#endif

// Далее объявления функций
extern "C" {
    LEVERGAME_API void SetScreenSize(float width, float height);
    LEVERGAME_API void AddRandomWind(GameState* state);
    LEVERGAME_API void InitGame(GameState* state, float playerMass, float weightMass);
    LEVERGAME_API void UpdateGame(GameState* state, float deltaTime);
}