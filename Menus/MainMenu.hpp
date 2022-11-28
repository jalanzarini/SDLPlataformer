#pragma once

#include "Menu.hpp"

class Game;

namespace Menus
{
    class MainMenu : public Menu
    {
    private:
        Button singleplayer;
        Button multiplayer;
        Button load;
        Button ld;
        Button exit;

    public:
        MainMenu(EventManager *ev, Game *gm);
        ~MainMenu();

        void update();
        void render();
    };
}