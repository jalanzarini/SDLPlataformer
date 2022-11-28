
#pragma once

#include <SDL2/SDL.h>
namespace Managers
{
    class EventManager
    {
    public:
        EventManager();
        ~EventManager();

        void listen(bool &isRunning);
        void keyUpdate();

        inline bool getKeyDown(SDL_Scancode key) { return (keyStates[key] == 1); }
        inline bool getMBDown() { return mouseClick; }
        inline int getMouseX() { return mouseX; }
        inline int getMouseY() { return mouseY; }
        inline bool getMouseClick() { return mouseClick; }

    private:
        int mouseX, mouseY;
        bool mouseClick, lastMouseClick;
        SDL_Event outputEvent;
        const Uint8 *keyStates;
    };
}