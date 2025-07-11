cmake_minimum_required(VERSION 3.31)
project(LeverGameLib)

set(CMAKE_CXX_STANDARD 17)

# Указываем где искать заголовочные файлы
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/.)

# Создаем shared библиотеку (только .cpp файлы)
add_library(LeverGameLib SHARED
        LeverGameLib.cpp
        LeverGameLib.h
        Effects/WindEffect/WindEffect.cpp
        Effects/WindEffect/WindEffect.h
        Physics/PhysicsEngine.cpp
        Physics/PhysicsEngine.h
#        Objects/Player/Player.cpp
#        Objects/Player/Player.h
#        Objects/Cup/Cup.cpp
#        Objects/Cup/Cup.h
#        Objects/Weight/Weight.cpp
#        Objects/Weight/Weight.h
        Core/GameConstants.h
        Core/GameState.h
)

# Правильное определение для экспорта функций
target_compile_definitions(LeverGameLib PRIVATE LEVERGAME_EXPORTS)

# Копируем DLL в удобное место после сборки (опционально)
#if(WIN32)
#    add_custom_command(TARGET LeverGameLib POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy
#            $<TARGET_FILE:LeverGameLib>
#            ${CMAKE_BINARY_DIR}/$<TARGET_FILE_NAME:LeverGameLib>
#    )
#endif()