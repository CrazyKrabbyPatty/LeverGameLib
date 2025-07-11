//
// Created by CrazyKrabbyPatty on 10.07.2025.
//

#pragma once

namespace GameConstants {
    // Размеры окна
    inline float ScreenWidth = 800.0f;  // inline для одной копии переменной
    inline float ScreenHeight = 600.0f;

    // Физические константы
    constexpr float MAX_ANGLE = 0.785f;  // 45 градусов в радианах
    constexpr float GRAVITY = 9.8f;
    constexpr float LEVER_LENGTH = 2.0f;

    // Настройки ветра
    constexpr float WIND_MIN_STRENGTH = -15.0f;
    constexpr float WIND_MAX_STRENGTH = 15.0f;
    constexpr float WIND_DURATION = 3.0f;
}

