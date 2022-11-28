#pragma once

#include <vector>
#include <list>
using namespace std;

#include "Player.hpp"
#include "Enemy.hpp"
#include "Obstacle.hpp"
#include "Plataform.hpp"
#include "Ground.hpp"
using namespace Entities;
using namespace Characters;
using namespace Obstacles;

namespace Managers
{
    class CollisionManager
    {
    private:
        vector<Enemy *> LIs;
        list<Obstacle *> LOs;
        Player *pl;
        Player *pl2;
        Ground *gnd;

    public:
        CollisionManager();
        ~CollisionManager();
        void clean();

        inline void setPlayer(Player *player) { pl = player; }
        inline void setPlayer2(Player *player) { pl2 = player; }
        inline void setGND(Ground *g) { gnd = g; }
        inline void insertEnemy(Enemy *en) { LIs.push_back(en); }
        inline void insertObs(Obstacle *obs) { LOs.push_back(obs); }

        void knockback(Player *pl, bool isSpike = true);
        bool intersect(Entity *ent1, Entity *ent2);
        int isColliding(Entity *ent1, Entity *ent2);
                
        void PlEnemyCollision();
        void projCollision();
        void enemyCollision();
        void obsCollision();
        void groundCollision();

        void Execute();
    };
}