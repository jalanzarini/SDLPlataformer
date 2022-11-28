#pragma once

#include "Obstacle.hpp"

namespace Entities
{
    namespace Obstacles
    {
        class Barrel : public Obstacle
        {
        private:
            int weight;

        public:
            Barrel();
            ~Barrel();

            void move() override;

            void update();
            void save(ofstream &arq);
        };
    }
}