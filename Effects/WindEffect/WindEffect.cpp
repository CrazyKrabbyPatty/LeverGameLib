#include "./WindEffect.h"
#include "../../Core/GameConstants.h"

namespace Effects {

    // Инициализация генератора случайных чисел
    std::mt19937 WindEffect::randomGenerator_(std::random_device{}());

    // Конструктор с параметрами
    WindEffect::WindEffect(float strength, float position, float width, float duration, int direction)
        : strength_(strength), position_(position), width_(width), duration_(duration), direction_(direction) {
        // Можно добавить валидацию параметров
        if (width_ <= 0) width_ = 0.1f;
    }

    // Фабричный метод для случайного ветра
    WindEffect WindEffect::CreateRandom() {
        std::uniform_real_distribution<float> strengthDist(-15.0f, 15.0f);
        std::uniform_real_distribution<float> posDist(-1.0f, 1.0f);
        std::uniform_real_distribution<float> widthDist(0.1f, 0.3f);
        std::uniform_int_distribution<int> dirDist(-1, 1);

        return WindEffect(
            strengthDist(randomGenerator_),
            posDist(randomGenerator_),
            widthDist(randomGenerator_),
            3.0f,  // Длительность 3 секунды
            dirDist(randomGenerator_) == 0 ? 1 : dirDist(randomGenerator_)  // Направление (-1 или 1)
        );
    }

    // Применение эффекта
    void WindEffect::Apply(GameState& state) const {
        Effect newEffect;
        newEffect.type = EffectType::Wind;
        newEffect.strength = strength_ * direction_;  // Учитываем направление
        newEffect.position = position_;
        newEffect.duration = duration_;

        if (state.activeEffectsCount < 10) {
            state.activeEffects[state.activeEffectsCount] = newEffect;
            state.activeEffectsCount++;
        }
    }

} // namespace Effects