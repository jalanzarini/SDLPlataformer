#include "Trooper.hpp"

namespace Entities
{
    namespace Characters
    {
        Trooper::Trooper(Player *pl, Player *pl2) : Enemy(1, pl, pl2, true), bullet(new Projectile(false))
        {
            physics.setXVelocity(1);
            physics.setW(64);
            physics.setH(53);
            sprite.setSprite("assets/trooper.png", 0, 0, 64, 53);
        }

        Trooper::~Trooper()
        {
            delete bullet;
        }

        void Trooper::update()
        {
            if (!isActive)
                return;

            if (health <= 0)
            {
                Deactivate();
                player->addScorePoints(10);
            }
            if (rand() % 50 == 0)
            {
                bullet->fire(this->getPhysics()->getXPosition(), this->getPhysics()->getYPosition() + 20, physics.getMoveDirection());
            }

            if (physics.getYPosition() < 940)
            {
                physics.setXVelocity(0);
                physics.setMoveDirection(-1);
            }

            move();
        }

        void Trooper::save(ofstream &arq)
        {
            Physics *phy = this->getPhysics();
            arq << "2"
                << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << " " << phy->getXVelocity() << " " << phy->getYVelocity() << endl;
        }
    }
}