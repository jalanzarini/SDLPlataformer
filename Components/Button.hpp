#pragma once

#include "Ente.hpp"

namespace Menus
{
    class Button : public Ente
    {
    private:
        int x, y;
        int width, height;

    public:
        Button() : x(0), y(0), width(0), height(0){}
        ~Button(){}

        void setButton(int xPos, int yPos, int w, int h)
        {
            setX(xPos);
            setY(yPos);
            setWidth(w);
            setHeight(h);
        }

        inline const int getX() const { return x; }
        inline const int getY() const { return y; }
        inline const int getHeight() const { return height; }
        inline const int getWidth() const { return width; }

        inline void setX(int xPos) { x= xPos; }
        inline void setY(int yPos) { y= yPos; }
        inline void setWidth(int w) { width = w; }
        inline void setHeight(int h) { height = h; }

        inline void update() {}
        inline void render() { sprite.render(x, y); }
    };
}