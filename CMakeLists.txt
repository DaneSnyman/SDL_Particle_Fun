cmake_minimum_required(VERSION 3.0.0)
project(DGSParticleAnimation)

set(SDL2_INCLUDE_DIR C:/dev/vcpkg/installed/x64-windows/include/SDL2)
set(SDL2_LIB_DIR C:/dev/vcpkg/installed/x64-windows/lib)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

set(SOURCE_FILES main.cpp Screen.h Screen.cpp Particle.h Swarm.h Background.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
