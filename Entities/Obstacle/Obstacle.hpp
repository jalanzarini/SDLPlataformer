#pragma once

#include "Entity.hpp"
using namespace Entities;

namespace Entities
{
    namespace Obstacles
    {
        class Obstacle : public Entity
        {
        protected:
            bool isHarmful;

        public:
            Obstacle(bool harm) : isHarmful(harm) {type = "Obstacle";}
            Obstacle() : isHarmful(false) { type = "Obstacle";}
            ~Obstacle(){}

            inline virtual const int getDamage() const { return 0; }
            inline const bool getHarm() const { return isHarmful; }
            
            virtual void update() = 0;
            inline virtual void save(ofstream &arq) {}
        };
    }
}