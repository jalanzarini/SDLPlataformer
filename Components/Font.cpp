#include "Font.hpp"

Font::Font(int x, int y, int w, int h)
{
    TTF_Init();
    ST = TTF_OpenFont("assets/STJEDISE.TTF", 24);
    yellow = {255, 191, 0};
    surfaceMessage = TTF_RenderText_Solid(ST, "", yellow);
    Message = SDL_CreateTextureFromSurface(GraphicManager::getInstance()->getRenderer(), surfaceMessage);

    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = w;
    Message_rect.h = h;
}

Font::~Font()
{
}

void Font::setRect(int x, int y, int w, int h)
{
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = w;
    Message_rect.h = h;
}

void Font::setMessage(string s)
{
    surfaceMessage = TTF_RenderText_Solid(ST, s.c_str(), yellow);
    Message = SDL_CreateTextureFromSurface(GraphicManager::getInstance()->getRenderer(), surfaceMessage);
}

void Font::clean()
{
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void Font::render()
{
    SDL_RenderCopy(GraphicManager::getInstance()->getRenderer(), Message, NULL, &Message_rect);
}

void Font::update(string s)
{
    clean();
    surfaceMessage = TTF_RenderText_Solid(ST, s.c_str(), yellow);
    Message = SDL_CreateTextureFromSurface(GraphicManager::getInstance()->getRenderer(), surfaceMessage);
}
