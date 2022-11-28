
#pragma once

#include <SDL2/SDL.h>
#include <string>
namespace Managers
{
    class GraphicManager
    {
    public:
        inline SDL_Window *getWindow() const { return window; }
        inline SDL_Renderer *getRenderer() const { return renderer; }
        inline static int getWidth() { return sWidth; }
        inline static int getHeight() { return sHeight; }

        inline static GraphicManager *getInstance() { return instance = (instance == nullptr) ? new GraphicManager() : instance; }
        inline void deleteInstance() { delete instance; }

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        static int sWidth, sHeight;

        static GraphicManager *instance;
        GraphicManager();
        ~GraphicManager();
    };
}