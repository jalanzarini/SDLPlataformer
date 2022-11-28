#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace Characters
    {
        class Maul : public Enemy
        {
        private:
            int darkness;

        public:
            Maul(Player *pl, Player *pl2);
            ~Maul();

            void doDamage(Player *pl) override;

            void update();
            void save(ofstream &arq);
        };
    }
}