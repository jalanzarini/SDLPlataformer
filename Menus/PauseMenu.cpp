#include "PauseMenu.hpp"
using namespace Menus;

#include "Game.hpp"

PauseMenu::PauseMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/bg.jpg", 0, 0, 1920, 1080, 1);
    lastLevel = 0;

    mainMenu.setButton(780, 900, 360, 100);
    mainMenu.setSprite("assets/Menu/mainmenu.png", 0, 0, 360, 100, 1);

    levelMenu.setButton(762, 800, 396, 100);
    levelMenu.setSprite("assets/Menu/levelmenu.png", 0, 0, 396, 100, 1);

    saveLevel.setButton(765, 700, 391, 100);
    saveLevel.setSprite("assets/Menu/savelevel.png", 0, 0, 391, 100, 1);
}
PauseMenu::~PauseMenu()
{
    events = nullptr;
}

void PauseMenu::update()
{
    if (events->getKeyDown(SDL_SCANCODE_Q))
    {
        game->setGameState(lastLevel);
    }

    if (isButtonClicked(mainMenu))
    {
        game->setGameState(-2);
        game->resetLevels();
    }
    if (isButtonClicked(levelMenu))
    {
        game->setGameState(0);
        game->resetLevels();
    }

    if (isButtonClicked(saveLevel))
    {
        if (lastLevel == 1)
            game->saveLevel1();
        if (lastLevel == 2)
            game->saveLevel2();

        game->resetLevels();
        game->setGameState(-2);
    }
}
void PauseMenu::render()
{
    sprite.render();
    mainMenu.render();
    levelMenu.render();
    saveLevel.render();
}