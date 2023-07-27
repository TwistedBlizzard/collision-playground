#include "Engine/InputManager.hpp"

InputManager::InputManager(InputFlags* inputFlags) :
m_inputFlags(inputFlags)
{}

InputManager::~InputManager()
{}

void InputManager::HandleEvent(SDL_Event event)
{
    if (event.type == SDL_EVENT_KEY_DOWN)
        KeyDown(event.key.keysym.sym);

    if (event.type == SDL_EVENT_KEY_UP)
        KeyUp(event.key.keysym.sym);
}

InputActions InputManager::GetAction(SDL_Keycode code)
{
    InputActions action = InputActions::None;

    switch(code)
    {
    case SDLK_UP:
    case SDLK_w:
        action = InputActions::Up;
        break;
    case SDLK_DOWN:
    case SDLK_s:
        action = InputActions::Down;
        break;
    case SDLK_LEFT:
    case SDLK_a:
        action = InputActions::Left;
        break;
    case SDLK_RIGHT:
    case SDLK_d:
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