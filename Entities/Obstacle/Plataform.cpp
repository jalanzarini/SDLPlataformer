
#include "Plataform.hpp"

using namespace Entities;
using namespace Obstacles;

Plataform::Plataform(int tp, bool fl): floating(fl), type(tp)
{

    if(type == 1){
        sprite.setSprite("assets/129x44plat.jpg", 0, 0, 129, 44);
        physics.setW(129);
        physics.setH(44);
    }
    else if(type == 2){
        sprite.setSprite("assets/129x21plat.jpg", 0, 0, 129, 21);
        physics.setW(129);
        physics.setH(21);
    }
    else if(type == 3){
        sprite.setSprite("assets/43x43Wplat.jpg", 0, 0, 43, 43);
        physics.setW(43);
        physics.setH(43);
    }
    else if(type == 4){
        sprite.setSprite("assets/43x43Lplat.jpg", 0, 0, 43, 43);
        physics.setW(43);
        physics.setH(43);
    }
    else if(type == 5){
        sprite.setSprite("assets/43x43mplat.jpg", 0, 0, 43, 43);
        physics.setW(43);
        physics.setH(43);
    }
    else if(type == 6){
        sprite.setSprite("assets/43x43Rplat.jpg", 0, 0, 43, 43);
        physics.setW(43);
        physics.setH(43);
    }
}

Plataform::~Plataform()
{
}

void Plataform::update()
{
    move();
}

void Plataform::save(ofstream &arq)
{
    Physics *phy = this->getPhysics();
    arq << "7" << " " << this->getType() << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() - phy->getYVelocity() << endl;
}
