#include "CollisionManager.hpp"
#include <iostream>

using namespace Managers;

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::clean()
{
    LIs.clear();
    LOs.clear();
}

bool CollisionManager::intersect(Entity *ent1, Entity *ent2)
{
    int x1 = ent1->getPhysics()->getXPosition();
    int y1 = ent1->getPhysics()->getYPosition();
    int w1 = ent1->getPhysics()->getW();
    int h1 = ent1->getPhysics()->getH();

    int x2 = ent2->getPhysics()->getXPosition();
    int y2 = ent2->getPhysics()->getYPosition();
    int w2 = ent2->getPhysics()->getW();
    int h2 = ent2->getPhysics()->getH();

    return (x1 + w1 > x2 && x1 < x2 + w2 && y1 + h1 > y2 && y1 < y2 + h2);
}

int CollisionManager::isColliding(Entity *ent1, Entity *ent2)
{
    int x1 = ent1->getPhysics()->getXPosition();
    int y1 = ent1->getPhysics()->getYPosition();
    int w1 = ent1->getPhysics()->getW();
    int h1 = ent1->getPhysics()->getH();
    float vx = ent1->getPhysics()->getXVelocity();
    float vy = ent1->getPhysics()->getYVelocity();

    int x2 = ent2->getPhysics()->getXPosition();
    int y2 = ent2->getPhysics()->getYPosition();
    int w2 = ent2->getPhysics()->getW();
    int h2 = ent2->getPhysics()->getH();

    if (x1 + w1 + vx > x2 &&
        x1 + vx < x2 + w2 &&
        y1 + h1 > y2 &&
        y1 < y2 + h2)
    {
        if (x1 < x2)
        {

            ent1->getPhysics()->setXPosition(x2 - w1 - 5);

            return 1; // Right Collision
        }
        else if (x1 > x2)
        {

            ent1->getPhysics()->setXPosition(x2 + w2 + 5);

            return 3; // Left Collision
        }
    }

    if (x1 + w1 > x2 &&
        x1 < x2 + w2 &&
        y1 + h1 + vy > y2 &&
        y1 + vy < y2 + h2)
    {
        if (y1 > y2)
        {
            ent1->getPhysics()->setYPosition(y2 + h2 + 5);
            ent1->getPhysics()->setYVelocity(0);
            return 4; // Top Collision
        }
        else if (y1 < y2)
        {
            ent1->setIsGrounded(true);
            ent1->getPhysics()->setYPosition(y2 - h1 - 5);
            ent1->getPhysics()->setYVelocity(0);
            return 2; // Bottom Collision
        }
    }

    return 0;
}

void CollisionManager::enemyCollision()
{
    vector<Enemy *>::iterator it;
    list<Obstacle *>::iterator it2;

    for (it = LIs.begin(); it != LIs.end(); it++)
    {
        for (it2 = LOs.begin(); it2 != LOs.end(); it2++)
        {
            if(!(*it2)->getHarm()){
                if (isColliding(static_cast<Entity *>(*it), static_cast<Entity *>(*it2)) % 2 == 1)
                {
                    (*it)->getPhysics()->setMoveDirection(-(*it)->getPhysics()->getMoveDirection());
                    (*it)->getPhysics()->setXVelocity(-(*it)->getPhysics()->getXVelocity());
                }
            }
        }
    }
}

void CollisionManager::knockback(Player *pl, bool isSpike)
{
    if(isSpike)
        pl->getPhysics()->setXVelocity(30 * pl->getPhysics()->getMoveDirection());
    else
        pl->getPhysics()->setXVelocity(-30 * pl->getPhysics()->getMoveDirection());
    
    pl->getPhysics()->setXPosition(pl->getPhysics()->getXPosition() + pl->getPhysics()->getXVelocity());
    pl->getPhysics()->setYVelocity(-15);
    pl->getPhysics()->setYPosition(pl->getPhysics()->getYPosition() + pl->getPhysics()->getYVelocity());
}

void CollisionManager::obsCollision()
{
    list<Obstacle *>::iterator it;
    list<Obstacle *>::iterator it2;

    for (it = LOs.begin(); it != LOs.end(); it++)
    {
        if (isColliding(static_cast<Entity *>(pl), static_cast<Entity *>(*it)) && (*it)->getHarm())
        {
            pl->takeDamage((*it)->getDamage());
            knockback(pl);
        }
        if (isColliding(static_cast<Entity *>(pl2), static_cast<Entity *>(*it)) && (*it)->getHarm())
        {
            pl2->takeDamage((*it)->getDamage());
            knockback(pl2);
        }
    }

    for (it = LOs.begin(); it != LOs.end(); it++)
    {
        for (it2 = it; it2 != LOs.end(); it2++)
        {
            isColliding(static_cast<Entity *>(*it), static_cast<Entity *>(*it2));
        }
    }
}

void CollisionManager::groundCollision()
{
    vector<Enemy *>::iterator it;
    list<Obstacle *>::iterator it2;

    for (it = LIs.begin(); it != LIs.end(); it++)
    {
        isColliding(static_cast<Entity *>(*it), static_cast<Entity *>(gnd));
    }
    for (it2 = LOs.begin(); it2 != LOs.end(); it2++)
    {
        isColliding(static_cast<Entity *>(*it2), static_cast<Entity *>(gnd));
    }

    isColliding(static_cast<Entity *>(pl), static_cast<Entity *>(gnd));
    isColliding(static_cast<Entity *>(pl2), static_cast<Entity *>(gnd));
}

void CollisionManager::projCollision()
{
    vector<Enemy *>::iterator it = LIs.begin();
    list<Obstacle *>::iterator it2 = LOs.begin();

    while (it2 != LOs.end())
    {
        if(!(*it2)->getHarm()){
            if (intersect(static_cast<Entity *>(pl->getBullet()), static_cast<Entity *>(*it2)) && pl->getBullet()->getIsActive())
                pl->getBullet()->Deactivate();

            if (intersect(static_cast<Entity *>(pl2->getBullet()), static_cast<Entity *>(*it2)) && pl2->getBullet()->getIsActive())
                pl2->getBullet()->Deactivate();
        }
        it2++;
    }

    if (intersect(static_cast<Entity *>(pl->getBullet()), static_cast<Entity *>(gnd)) && pl->getBullet()->getIsActive())
        pl->getBullet()->Deactivate();

    if (intersect(static_cast<Entity *>(pl2->getBullet()), static_cast<Entity *>(gnd)) && pl2->getBullet()->getIsActive())
        pl2->getBullet()->Deactivate();

    it2 = LOs.begin();
    while (it != LIs.end())
    {
        if ((*it)->getIsShooter())
        {
            it2 = LOs.begin();
            while (it2 != LOs.end())
            {
                if (intersect(static_cast<Entity *>((*it)->getBullet()), static_cast<Entity *>(*it2)) && (*it)->getBullet()->getIsActive())
                {
                    (*it)->getBullet()->Deactivate();
                    break;
                }
                it2++;
            }
            // Enemy Player
            if (intersect(static_cast<Entity *>((*it)->getBullet()), static_cast<Entity *>(pl)) && (*it)->getBullet()->getIsActive() && pl->getIsActive())
            {
                (*it)->getBullet()->Deactivate();
                pl->takeDamage();
            }
            // Enemy Player2
            if (intersect(static_cast<Entity *>((*it)->getBullet()), static_cast<Entity *>(pl2)) && (*it)->getBullet()->getIsActive() && pl2->getIsActive())
            {
                (*it)->getBullet()->Deactivate();
                pl2->takeDamage();
            }

            if (intersect(static_cast<Entity *>((*it)->getBullet()), static_cast<Entity *>(gnd)) && (*it)->getBullet()->getIsActive())
                (*it)->getBullet()->Deactivate();
        }
        // Player Enemy
        if (intersect(static_cast<Entity *>(pl->getBullet()), static_cast<Entity *>(*it)) && pl->getBullet()->getIsActive() && (*it)->getIsActive())
        {
            pl->getBullet()->Deactivate();
            (*it)->takeDamage();
        }
        // Player2 Enemy
        if (intersect(static_cast<Entity *>(pl2->getBullet()), static_cast<Entity *>(*it)) && pl2->getBullet()->getIsActive() && (*it)->getIsActive())
        {
            pl2->getBullet()->Deactivate();
            (*it)->takeDamage();
        }
        it++;
    }
}

void CollisionManager::PlEnemyCollision()
{
    vector<Enemy *>::iterator it = LIs.begin();

    while (it != LIs.end())
    {
        if ((*it)->getIsActive())
        {
            if (isColliding(static_cast<Entity *>(pl), static_cast<Entity *>(*it)) && !(*it)->getIsShooter()){
                (*it)->doDamage(pl);
                knockback(pl, false);
            }

            if (isColliding(static_cast<Entity *>(pl2), static_cast<Entity *>(*it)) && !(*it)->getIsShooter()){
                (*it)->doDamage(pl2);
                knockback(pl2, false);
            }
        }
        it++;
    }
}

void CollisionManager::Execute()
{
    PlEnemyCollision();
    projCollision();
    obsCollision();
    enemyCollision();
    groundCollision();
}