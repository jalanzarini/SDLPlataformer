#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace Characters
    {
        class Vader : public Enemy
        {
        private:
            int force;

        public:
            Vader(Player* pl, Player* pl2);
            ~Vader();

            void doDamage(Player* pl) override;

            void update();
            void save(ofstream &arq);
        };
    }
}