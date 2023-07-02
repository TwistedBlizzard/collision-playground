cmake_minimum_required(VERSION 3.17)

project(CollisionPlayground
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

option(USE_VENDORED_SDL TRUE)

if(USE_VENDORED_SDL)
    set(SDL3_VENDORED TRUE)
    set(SDL3IMAGE_VENDORED TRUE)

    include(FetchContent)

    FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL
        GIT_TAG origin/main
        OVERRIDE_FIND_PACKAGE
    )

    FetchContent_Declare(
        SDL3_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
        GIT_TAG origin/main
        OVERRIDE_FIND_PACKAGE
    )
endif()

add_subdirectory(src)
add_subdirectory(apps)