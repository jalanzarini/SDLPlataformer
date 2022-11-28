#include "MainMenu.hpp"
using namespace Menus;

#include "Game.hpp"

MainMenu::MainMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/bg.jpg", 0, 0, 1920, 1080, 1);

    singleplayer.setButton(760, 600, 400, 86);
    singleplayer.setSprite("assets/Menu/singleplayer.png", 0, 0, 400, 86, 1);

    multiplayer.setButton(760, 700, 400, 92);
    multiplayer.setSprite("assets/Menu/multiplayer.png", 0, 0, 400, 92, 1);

    load.setButton(760, 800, 400, 97);
    load.setSprite("assets/Menu/loadsaved.png", 0, 0, 400, 97, 1);

    exit.setButton(100, 900, 177, 100);
    exit.setSprite("assets/Menu/exit.png", 0, 0, 177, 100, 1);

    ld.setButton(760, 900, 400, 85);
    ld.setSprite("assets/Menu/leaderboard.png", 0, 0, 400, 85, 1);
}
MainMenu::~MainMenu()
{
    events = nullptr;
}

void MainMenu::update()
{
    if (isButtonClicked(singleplayer))
    {
        game->setMultiplayer(false);
        game->setGameState(0);
    }

    if (isButtonClicked(multiplayer))
    {
        game->setMultiplayer(true);
        game->setGameState(0);
    }

    if (isButtonClicked(load))
    {
        game->setGameState(game->loadLVL());
    }

    if (isButtonClicked(exit))
    {
        game->setGameState(-10);
    }

    if (isButtonClicked(ld))
    {
        game->upLeaderboard();
        game->setGameState(4);
    }
}
void MainMenu::render()
{
    sprite.render();
    singleplayer.render();
    multiplayer.render();
    load.render();
    exit.render();
    ld.render();
}