#pragma once

#include <SDL2/SDL_ttf.h>
#include <iostream>
using namespace std;

#include "Ente.hpp"
#include "Font.hpp"

#include "EntityList.hpp"
using namespace Lists;

#include "Player.hpp"
#include "Spike.hpp"
#include "Barrel.hpp"
#include "Plataform.hpp"
#include "Vader.hpp"
#include "Trooper.hpp"
#include "Maul.hpp"
using namespace Entities;
using namespace Characters;
using namespace Obstacles;

#include "CollisionManager.hpp"
#include "EventManager.hpp"
using namespace Managers;

namespace Levels
{
    class Level : public Ente
    {
    protected:
        EntityList entList;
        CollisionManager colManager;

        EventManager *evManager;

        Ground *gnd;
        Player *p1;
        Player *p2;
        Font Score;
        Font p1Life;
        Font p2Life;

    public:
        Level(EventManager *ev);
        ~Level();

        void render();
        virtual void update() = 0;
        void clean();

        inline int getEnemySize() { return entList.getEnemySize(); }

        Spike* createSpike(int x, int y);
        Plataform* createPlataform(int x, int y, int type = 1);
        Barrel* createBarrel(int x, int y);
        Vader* createVader(int x, int y);

        virtual void spikeBulkInitialize() = 0;
        virtual void barrelBulkInitialize() = 0;
        virtual void vaderBulkInitialize() = 0;

        void groundInitialize();

        virtual void save() = 0;
    };
}