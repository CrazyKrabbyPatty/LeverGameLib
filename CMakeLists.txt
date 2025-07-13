cmake_minimum_required(VERSION 3.31)
project(LeverGameLib)

set(CMAKE_CXX_STANDARD 17)

# Создаем shared библиотеку (только .cpp файлы)
add_library(LeverGameLib SHARED
        LeverGameLib.cpp
        Effects/WindEffect/WindEffect.cpp
        Physics/PhysicsEngine.cpp
)

# Указываем где искать заголовочные файлы
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/.)

target_include_directories(LeverGameLib PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Effects/WindEffect
        ${CMAKE_CURRENT_SOURCE_DIR}/Core
        ${CMAKE_CURRENT_SOURCE_DIR}/Objects/Player
        ${CMAKE_CURRENT_SOURCE_DIR}/Physics
)

# Правильное определение для экспорта функций
target_compile_definitions(LeverGameLib PRIVATE LEVERGAME_EXPORTS)