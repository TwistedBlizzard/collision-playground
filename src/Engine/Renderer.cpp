#include "Engine/Renderer.hpp"

#include <cmath>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

#define SEGMENTS 36

Renderer::Renderer():
m_initialised(false),
m_renderer(nullptr)
{}

Renderer::~Renderer()
{}

void Renderer::Init()
{
    if (m_initialised)
        return;

    SDL_Window* window = nullptr;
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 20, 20, 20, 255);

    m_initialised = true;
}

Vector2f Renderer::GetWindowSize()
{
    return Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Renderer::Clear()
{
    SDL_RenderClear(m_renderer);
}

void Renderer::Present()
{
    SDL_RenderPresent(m_renderer);
}

void Renderer::DrawCircle(Vector2f position, float radius)
{
    SDL_FPoint points[SEGMENTS + 1];
    for (int i = 0; i < SEGMENTS; i++)
    {
        float angle = (360.0f / SEGMENTS) * i;
        angle *= M_PI / 180;

        points[i].x = sin(angle) * radius;
        points[i].x += position.x;
        points[i].y = cos(angle) * radius;
        points[i].y += position.y;
    }

    points[SEGMENTS] = points[0];

    SDL_SetRenderDrawColor(m_renderer, 255, 127, 20, 255);
    SDL_RenderLines(m_renderer, points, SEGMENTS + 1);
    SDL_SetRenderDrawColor(m_renderer, 20, 20, 20, 255);
}