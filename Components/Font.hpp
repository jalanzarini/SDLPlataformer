#pragma once

#include <SDL2/SDL_ttf.h>
#include <string>
using namespace std;

#include "Player.hpp"
using namespace Entities;
using namespace Characters;

#include "GraphicManager.hpp"

class Font
{
private:
    TTF_Font *ST;
    SDL_Color yellow;
    SDL_Surface *surfaceMessage;
    SDL_Texture *Message;
    SDL_Rect Message_rect;

public:
    Font(int x, int y, int w = 180, int h = 75);
    ~Font();

    void setRect(int x, int y, int w, int h);
    void setMessage(string s);

    void clean();
    void render();
    void update(string s);
};