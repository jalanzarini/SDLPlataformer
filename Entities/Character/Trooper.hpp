#pragma once

#include "Enemy.hpp"

namespace Entities
{
    namespace Characters
    {
        class Trooper : public Enemy
        {
        private:
            Projectile *bullet;

        public:
            Trooper(Player *pl, Player *pl2);
            ~Trooper();

            inline Projectile *getBullet() override { return bullet; }

            void update();
            void save(ofstream &arq);
        };
    }
}