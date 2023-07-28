file(GLOB HEADER_LIST CONFIGURE_DEPENDS ${CollisionPlayground_SOURCE_DIR}/include/Engine/*.hpp)

set(SOURCE_LIST
    Collider.cpp
    CollisionHandler.cpp
    Engine.cpp
    GameObject.cpp
    InputManager.cpp
    Player.cpp
    Renderer.cpp
    Timing.cpp)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)

add_library(Engine STATIC ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries(Engine PUBLIC SDL3::SDL3)
target_include_directories(Engine PUBLIC ../../include)

source_group(
    TREE "${PROJECT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_LIST})