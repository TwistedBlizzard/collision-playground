#include "Engine/InputManager.hpp"

InputManager::InputManager(InputFlags* inputFlags) :
m_inputFlags(inputFlags)
{}

InputManager::~InputManager()
{}

void InputManager::HandleEvent(SDL_Event event)
{
    if (event.type == SDL_EVENT_KEY_DOWN)
        KeyDown(event.key.key);

    if (event.type == SDL_EVENT_KEY_UP)
        KeyUp(event.key.key);
}

Vector2f InputManager::GetVector()
{
    Vector2f vector = Vector2f();

    if (*m_inputFlags & InputActions::Up)
        vector.y = -1;
    
    if (*m_inputFlags & InputActions::Down)
        vector.y += 1;

    if (*m_inputFlags & InputActions::Left)
        vector.x = -1;
    
    if (*m_inputFlags & InputActions::Right)
        vector.x += 1;

    return vector;
}

InputActions InputManager::GetAction(SDL_Keycode code)
{
    InputActions action = InputActions::None;

    switch(code)
    {
    case SDLK_UP:
    case SDLK_W:
        action = InputActions::Up;
        break;
    case SDLK_DOWN:
    case SDLK_S:
        action = InputActions::Down;
        break;
    case SDLK_LEFT:
    case SDLK_A:
        action = InputActions::Left;
        break;
    case SDLK_RIGHT:
    case SDLK_D:
        action = InputActions::Right;
        break;
    default:
        break;
    }

    return action;
}

void InputManager::KeyDown(SDL_Keycode code)
{
    *m_inputFlags |= GetAction(code);
}

void InputManager::KeyUp(SDL_Keycode code)
{
    *m_inputFlags &= ~GetAction(code);
}