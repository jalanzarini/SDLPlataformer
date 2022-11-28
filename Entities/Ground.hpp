
#pragma once

#include "GraphicManager.hpp"
using namespace Managers;
#include "Plataform.hpp"
using namespace Obstacles;
#include "Entity.hpp"

namespace Entities
{
    class Ground : public Entity
    {
    private:
        Plataform** platvector;
        int size;

    public:
        Ground();
        ~Ground();

        void update();
        void render() override;
        
        void save(ofstream &arq);
    };
}