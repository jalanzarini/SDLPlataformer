#include "Level.hpp"
using namespace Levels;

Level::Level(EventManager *ev) : evManager(ev), Score(870, 30), p1Life(100, 30), p2Life(1640, 30)
{
    cout << "Level Initialized " << endl;

    p1 = nullptr;
    p2 = nullptr;
    gnd = nullptr;
}

Level::~Level()
{
    cout << "Level Destroyed" << endl;

    delete gnd;

    evManager = nullptr;
    p1 = nullptr;
    p2 = nullptr;
    gnd = nullptr;
}

void Level::render()
{
    sprite.render();
    entList.renderAll();
    Score.render();
    p1Life.render();
    if(p2->getIsActive())
        p2Life.render();
}

void Level::clean()
{
    entList.clean();
    colManager.clean();
}

void Level::groundInitialize()
{
    gnd = new Ground();
    gnd->setDeletable(false);

    gnd->setPhysics(-129, gfx->getHeight() - 40, gfx->getWidth() + 258, 44, 0, 0, 0, 0);
    colManager.setGND(gnd);
}

Spike* Level::createSpike(int x, int y)
{
    Spike *spike = new Spike();
    spike->getPhysics()->setPosition(x, y);
    colManager.insertObs(static_cast<Obstacle *>(spike));
    entList.insert(static_cast<Entity *>(spike));
    return spike;
}

Plataform* Level::createPlataform(int x, int y, int type)
{
    Plataform *plataform = new Plataform(type);
    plataform->getPhysics()->setPosition(x, y);
    colManager.insertObs(static_cast<Obstacle *>(plataform));
    entList.insert(static_cast<Entity *>(plataform));
    return plataform;
}

Barrel* Level::createBarrel(int x, int y)
{
    Barrel *barrel = new Barrel();
    barrel->getPhysics()->setPosition(x, y);
    colManager.insertObs(static_cast<Obstacle *>(barrel));
    entList.insert(static_cast<Entity *>(barrel));
    return barrel;
}

Vader* Level::createVader(int x, int y)
{
    Vader *vader = new Vader(p1, p2);
    vader->getPhysics()->setPosition(x, y);
    entList.insert(static_cast<Entity *>(vader));
    colManager.insertEnemy(static_cast<Enemy *>(vader));
    return vader;
}

