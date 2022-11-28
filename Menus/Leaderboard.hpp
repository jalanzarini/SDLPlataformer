#pragma once

#include "Menu.hpp"
#include <map>
using namespace std;

#include "Font.hpp"
using namespace Components;

class Game;

namespace Menus
{
    class Leaderboard : public Menu
    {
    private:
        Button mainMenu;
        map<int, string> names;

    public:
        Leaderboard(EventManager *ev, Game*gm);
        ~Leaderboard();
        void clean();

        void setNames();
        void renderNames();
        void update();
        void render();
    };
}