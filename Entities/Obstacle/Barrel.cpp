#include "Barrel.hpp"

namespace Entities
{
    namespace Obstacles
    {
        Barrel::Barrel() : weight(((rand() % 1000) / 1000.0f) + 0.001)
        {
            physics.setW(45);
            physics.setH(64);
            sprite.setSprite("assets/barrel.png", 0, 0, 45, 64);
        }
        
        Barrel::~Barrel()
        {

        }

        void Barrel::move()
        {
            applyGravity();

            physics.setYVelocity(physics.getYVelocity() + physics.getYAcceleration() + weight);
            if (physics.getYVelocity() > 10)
                physics.setYVelocity(10);

            physics.setXPosition(physics.getXPosition() + physics.getXVelocity());
            physics.setYPosition(physics.getYPosition() + physics.getYVelocity());
        }

        void Barrel::update()
        {
            applyGravity();
            physics.setYVelocity(physics.getYVelocity() * weight);
            move();
        }

        void Barrel::save(ofstream &arq)
        {
            Physics *phy = this->getPhysics();
            arq << "5"
                << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() - phy->getYVelocity() << endl;
        }
    }
}