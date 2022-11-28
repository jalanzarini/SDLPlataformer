#include "Sprite.hpp"
using namespace Components;

#include <iostream>

#include "GraphicManager.hpp"
using namespace Managers;

Sprite::Sprite() : path(""), row(0), column(0), width(0), height(0), multiplier(1), texture(nullptr)
{
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
    texture = nullptr;
}

void Sprite::setSprite(string p, int c, int r, int w, int h, int m)
{
    setTexture(p);

    setRow(r);
    setColumn(c);
    setWidth(w);
    setHeight(h);
    setMultiplier(m);
}

void Sprite::setSprite(const char *p, int c, int r, int w, int h, int m)
{
    setTexture(p);

    setRow(r);
    setColumn(c);
    setWidth(w);
    setHeight(h);
    setMultiplier(m);
}

void Sprite::setTexture(string p)
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }

    try
    {
        SDL_Texture *tx = IMG_LoadTexture(GraphicManager::getInstance()->getRenderer(), p.c_str());
        if (tx != nullptr)
        {
            texture = tx;
        }
        else
        {
            throw(SDL_GetError());
        }
    }
    catch (const char *e)
    {
        std::cout << "Texture could not be loaded: " << e << std::endl;
        return;
    }
}

void Sprite::setTexture(const char *p)
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }

    try
    {
        SDL_Texture *tx = IMG_LoadTexture(GraphicManager::getInstance()->getRenderer(), p);
        if (tx != nullptr)
        {
            texture = tx;
        }
        else
        {
            throw(SDL_GetError());
        }
    }
    catch (const char *e)
    {
        std::cout << "Texture could not be loaded: " << e << std::endl;
        return;
    }
}

void Sprite::render(int x, int y, int moveDir)
{
    SDL_Rect srcRect = {column * width, row * height, width, height};
    SDL_Rect dstRect = {x, y, width * multiplier, height * multiplier};

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (moveDir == -1)
    {
        flip = SDL_FLIP_HORIZONTAL;
    }

    SDL_RenderCopyEx(GraphicManager::getInstance()->getRenderer(), texture, &srcRect, &dstRect, 0, NULL, flip);
}