#include "Game.hpp"

#include <string>
#include <iostream>
using namespace std;

GraphicManager *Game::gfx = GraphicManager::getInstance();

Game::Game() : player(new Player()), player2(new Player()), lvl1(&evManager, player, player2), lvl2(&evManager, player, player2), isRunning(true), gameState(-2), menu(&evManager, this), pause(&evManager, this), mainMenu(&evManager, this), over(&evManager, this), ld(&evManager, this)
{
    init();

    while (isRunning)
    {
        evManager.listen(isRunning);
        update();
        render();
    }
}

Game::~Game()
{
    resetLevels();
    GraphicManager::getInstance()->deleteInstance();

    delete player;
    delete player2;
}

void Game::init()
{
    player->setSprite("assets/solo.png", 0, 0, 64, 59, 1);
    player->setInputSystem(&evManager, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_W, SDL_SCANCODE_Q);
    player->setDeletable(false);
    player->setType("Player1");

    player2->setSprite("assets/chew.png", 0, 0, 44, 64, 1);
    player2->setInputSystem(&evManager, SDL_SCANCODE_J, SDL_SCANCODE_L, SDL_SCANCODE_I, SDL_SCANCODE_U);
    player2->setDeletable(false);
    player2->setType("Player2");
}

void Game::update()
{
    if (evManager.getKeyDown(SDL_SCANCODE_ESCAPE) && (gameState == 1 || gameState == 2))
    {
        pause.setLastLevel(gameState);
        gameState = -1;
    }

    if (player->getPhysics()->getYPosition() > 2000)
        player->Deactivate();
    if (player2->getPhysics()->getYPosition() > 2000)
        player2->Deactivate();

    if (!player->getIsActive() && !player2->getIsActive())
    {
        gameState = 3;
        over.setPoints(Player::getScorePoints());
        player->reset();
        player2->reset();
        resetLevels();
    }

    switch (gameState)
    {
    case -2:
        mainMenu.update();
        break;
    case -1:
        pause.update();
        break;
    case 0:
        menu.update();
        break;
    case 1:
        lvl1.update();
        if (player->getPhysics()->getXPosition() >= 1790 || player2->getPhysics()->getXPosition() >= 1790)
        {
            gameState = 2;
            Level2Initialize();
        }
        break;
    case 2:
        lvl2.update();
        if (player->getPhysics()->getXPosition() >= 1790 || player2->getPhysics()->getXPosition() >= 1790)
        {
            gameState = 3;
            over.setPoints(Player::getScorePoints());
        }
        break;
    case 3:
        over.update();
        break;
    case 4:
        ld.update();
        break;
    default:
        isRunning = false;
        break;
    }
}

void Game::render()
{
    SDL_RenderClear(gfx->getRenderer());
    switch (gameState)
    {
    case -2:
        mainMenu.render();
        break;
    case -1:
        pause.render();
        break;
    case 0:
        menu.render();
        break;
    case 1:
        lvl1.render();
        break;
    case 2:
        lvl2.render();
        break;
    case 3:
        over.render();
        break;
    case 4:
        ld.render();
        break;
    default:
        isRunning = false;
        break;
    }
    SDL_RenderPresent(gfx->getRenderer());
}

void Game::resetLevels()
{
    lvl1.clean();
    lvl2.clean();
    player->reset();
    player2->reset();
}

void Game::Level1Initialize()
{
    lvl1.initialize(player, player2, multiplayer);
}

void Game::Level2Initialize()
{
    lvl2.initialize(player, player2, multiplayer);
}

void Game::saveLevel1()
{
    lvl1.save();
}

void Game::saveLevel2()
{
    lvl2.save();
}

int Game::loadLVL()
{
    int l;
    ifstream arq;
    arq.open("da.txt", ios::in);
    arq >> l;
    arq.close();

    if (l == 1)
        return lvl1.load();
    return lvl2.load();
}

void Game::upLeaderboard()
{
    ld.setNames();
}
