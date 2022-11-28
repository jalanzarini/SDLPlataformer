#include "Ground.hpp"

namespace Entities
{
    Ground::Ground(): size(17)
    {
        platvector = (Plataform**)malloc(size*sizeof(Plataform*));
        for(int i = 0 ; i < size ; i++)
        {
            platvector[i] = new Plataform();
            platvector[i]->getPhysics()->setPosition(i*129-129, GraphicManager::getInstance()->getHeight() - 40);
        }
    }
    Ground::~Ground()
    {
        for(int i = 0; i < size ; i++)
        {
            delete platvector[i];
            platvector[i] = nullptr;
        }
        free(platvector);
    }

    void Ground::update()
    {

    }

    void Ground::render()
    {
        for(int i = 0 ; i < size ; i++)
        {
            platvector[i]->render();
        }
    }

    void Ground::save(ofstream &arq)
    {

    }
}