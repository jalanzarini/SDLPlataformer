#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace Characters
    {
        class Character : public Entity
        {
        protected:
            int health;

        public:
            Character(int hp) : health(hp){}
            ~Character(){}

            inline void setHealth(int hp) { health = hp; }
            inline const int getHealth() const { return health; }
            inline void takeDamage(int dm = 1) { health -= dm; }

            virtual void update() = 0;
            inline virtual void save(ofstream &arq){}
        };
    }
}