
#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    class Plataform : public Obstacle
    {
    private:
        bool floating;
        int type;

    public:
        Plataform(int tp = 1, bool fl = false);
        ~Plataform();

        inline int getType() { return type; }

        void update();
        void save(ofstream &arq);
    };
}