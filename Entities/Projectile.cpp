#include "Projectile.hpp"

namespace Entities
{
    Projectile::Projectile(bool ips) : isPlayerShooted(ips)
        {
            Deactivate();
            physics.setW(48);
            physics.setH(10);
            sprite.setSprite("assets/laser.png", 0, 0, 48, 10, 1);
        }
        Projectile::~Projectile()
        {

        }

        void Projectile::fire(int x, int y, int dir)
        {
            if (!isActive)
            {
                Activate();
                physics.setPosition(x, y);
                physics.setVelocity(80 * dir, -2);
            }
        }

        void Projectile::update()
        {
            if (isActive)
            {
                move();
                if (physics.getXPosition() < -100 || physics.getXPosition() > GraphicManager::getWidth() + 100)
                    Deactivate();
            }
        }
        void Projectile::save(ofstream &arq)
        {
            Physics *phy = this->getPhysics();
            arq << "8"
                << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << " " << phy->getXVelocity() << " " << phy->getYVelocity() << endl;
        }
}