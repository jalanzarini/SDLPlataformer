#include "EntityList.hpp"
using namespace Lists;

#include <iostream>
#include <fstream>
using namespace std;

#include "Plataform.hpp"

EntityList::EntityList() : entList()
{
}

EntityList::~EntityList()
{
}

void EntityList::renderAll()
{
    List<Entity *>::iterator it;
    for (it = entList.begin(); it != nullptr; ++it)
    {
        (*it)->render();
    }
}

void EntityList::updateAll()
{
    List<Entity *>::iterator it;
    for (it = entList.begin(); it != nullptr; ++it)
    {
        (*it)->update();
    }
}

void EntityList::insert(Entity *entity)
{
    entList.insert(entity);
}

void EntityList::clean()
{
    entList.clean();
}

void EntityList::save(string name, int lvlnum)
{
    List<Entity *>::iterator it;
    it = entList.begin();

    ofstream arq;
    arq.open(name, ios::out | ios::trunc);
    arq << lvlnum << endl;
    while (it != nullptr)
    {
        (*it)->save(arq);
        ++it;
    }

    arq.close();
}

int EntityList::getEnemySize()
{
    int i = 0;
    List<Entity *>::iterator it;
    for (it = entList.begin(); it != nullptr; ++it)
    {
        if((*it)->getIsActive() && (*it)->getType() == "Enemy")
            i++;
    }

    return i;
}
