#include "LevelMenu.hpp"
using namespace Menus;

#include "Game.hpp"

LevelMenu::LevelMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/bg.jpg", 0, 0, 1920, 1080, 1);

    lvl1.setButton(822, 700, 277, 100);
    lvl1.setSprite("assets/Menu/level1.png", 0, 0, 277, 100, 1);

    lvl2.setButton(819, 800, 282, 100);
    lvl2.setSprite("assets/Menu/level2.png", 0, 0, 282, 100, 1);

    mainMenu.setButton(780, 900, 360, 100);
    mainMenu.setSprite("assets/Menu/mainmenu.png", 0, 0, 360, 100, 1);
}
LevelMenu::~LevelMenu()
{
    events = nullptr;
}

void LevelMenu::update()
{
    if (isButtonClicked(lvl1))
    {
        game->Level1Initialize();
        game->setGameState(1);
    }

    if (isButtonClicked(lvl2))
    {
        game->Level2Initialize();
        game->setGameState(2);
    }

    if (isButtonClicked(mainMenu))
    {
        game->setGameState(-2);
    }
}
void LevelMenu::render()
{
    sprite.render();
    lvl1.render();
    lvl2.render();
    mainMenu.render();
}