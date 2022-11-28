#include "EventManager.hpp"
using namespace Managers;

#include <iostream>
using namespace std;

EventManager::EventManager() : keyStates(SDL_GetKeyboardState(nullptr)), mouseClick(false), lastMouseClick(false)
{
    cout << "Event Manager Initialized" << endl;
}

EventManager::~EventManager()
{
    keyStates = nullptr;
    cout << "Event Manager Deleted" << endl;
}

void EventManager::listen(bool &isRunning)
{
    mouseClick = false;

    while (SDL_PollEvent(&outputEvent))
    {
        switch (outputEvent.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            keyUpdate();
            break;
        case SDL_KEYUP:
            keyUpdate();
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (!lastMouseClick)
            {
                mouseClick = true;
                lastMouseClick = true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            lastMouseClick = false;
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&mouseX, &mouseY);
            break;
        }
    }
}

void EventManager::keyUpdate()
{
    keyStates = SDL_GetKeyboardState(nullptr);
}