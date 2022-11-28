#pragma once

#include "Entity.hpp"
#include <iostream>
using namespace std;

namespace Entities
{
    class Projectile : public Entity
    {
    private:
        bool isPlayerShooted;

    public:
        Projectile(bool ips);
        ~Projectile();

        void fire(int x, int y, int dir);

        void update();
        void save(ofstream &arq);
    };
}