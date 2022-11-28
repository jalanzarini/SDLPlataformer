#pragma once

#include "List.hpp"

#include "Entity.hpp"
using namespace Entities;

#include <string>
using namespace std;

namespace Lists
{
    class EntityList
    {
    private:
        List<Entity*> entList;

    public:
        EntityList();
        ~EntityList();

        void clean();
        void renderAll();
        void updateAll();
        void insert(Entity *entity);
        void save(string name, int lvlnum);

        int getEnemySize();
    };
}
