#include "Leaderboard.hpp"
using namespace Menus;

#include <fstream>
using namespace std;

#include "Game.hpp"

Leaderboard::Leaderboard(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/galaxy.jpg", 0, 0, 1920, 1080, 1);

    mainMenu.setButton(780, 900, 360, 100);
    mainMenu.setSprite("assets/Menu/mainmenu.png", 0, 0, 360, 100, 1);
}
Leaderboard::~Leaderboard()
{
    //clean();
    events = nullptr;
}

void Leaderboard::update()
{
    if (isButtonClicked(mainMenu))
    {
        game->setGameState(-2);
    }
}

void Leaderboard::setNames()
{
    ifstream arq;
    arq.open("lb.txt", ios::in);

    string name, points;

    while(!arq.eof())
    {
        arq >> points >> name;
        names.insert(pair<int, string>(atoi(points.c_str()), name + ".........." + points));
    }
}

void Leaderboard::renderNames()
{
    map<int, string>::reverse_iterator it = names.rbegin();

    int i = 1;
    while(it != names.rend())
    {
        Font atual(560, 100*i, 800, 100);
        atual.setMessage(it->second);
        atual.render();
        it++;
        i++;
    }
}

void Leaderboard::render()
{
    sprite.render();
    mainMenu.render();
    renderNames();
}