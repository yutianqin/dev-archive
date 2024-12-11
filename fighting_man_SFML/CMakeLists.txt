
cmake_minimum_required(VERSION 3.15)

project(Hunter)

add_executable(Hunter src/main.cpp src/Bullet.cpp src/Hunter.cpp src/Enemy.cpp src/Bullet.hpp src/Hunter.hpp src/Enemy.hpp)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/fly.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ground.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/duck.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/duckfliped.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/nightsky.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/spaceship.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ssfliped.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

target_link_libraries(Hunter sfml-graphics)

target_compile_options(Hunter PUBLIC -std=c++17)