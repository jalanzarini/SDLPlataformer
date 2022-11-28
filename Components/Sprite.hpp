#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
using namespace std;

namespace Components
{
    class Sprite
    {
    private:
        string path;
        SDL_Texture *texture;

        int row;
        int column;
        int width;
        int height;
        int multiplier;

    public:
        Sprite();
        ~Sprite();

        void setSprite(string p, int c, int r, int w, int h, int m = 1);
        void setSprite(const char *p, int c, int r, int w, int h, int m = 1);

        inline const SDL_Texture *getTexture() const { return texture; }
        inline const int getRow() const { return row; }
        inline const int getColumn() const { return column; }
        inline const int getWidth() const { return width; }
        inline const int getHeight() const { return height; }
        inline const int getMultiplier() const { return multiplier; }

        inline void setPath(string p) { path = p; }
        inline void setTexture(string p);
        inline void setTexture(const char *p);
        inline void setRow(int r) { row = r; }
        inline void setColumn(int c) { column = c; }
        inline void setWidth(int w) { width = w; }
        inline void setHeight(int h) { height = h; }
        inline void setMultiplier(int m) { multiplier = m; }

        void render(int x = 0, int y = 0, int moveDir = 1);
    };
}