#pragma once

#include "Ente.hpp"

#include "EventManager.hpp"
using namespace Managers;

#include "Button.hpp"

#include <iostream>
using namespace std;

class Game;

namespace Menus
{
    class Menu : public Ente
    {
    protected:
        EventManager *events;
        Game *game;

    public:
        Menu(EventManager *ev, Game *gm) : events(ev), game(gm){};
        ~Menu(){};

        bool isButtonClicked(Button &b)
        {
            int bX = b.getX();
            int bY = b.getY();
            int bW = b.getWidth();
            int bH = b.getHeight();

            int mouseX = events->getMouseX();
            int mouseY = events->getMouseY();

            if (events->getMouseClick() && mouseX < bX + bW && mouseX > bX && mouseY > bY && mouseY < bY + bH)
            {
                return true;
            }
            return false;
        }

        virtual void update() = 0;
        virtual void render() = 0;
    };
}