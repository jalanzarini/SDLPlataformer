#include "Maul.hpp"

namespace Entities
{
    namespace Characters
    {
        Maul::Maul(Player *pl, Player *pl2) : Enemy(1, pl, pl2)
        {
            darkness = (rand() % 3) + 1;
            physics.setXVelocity(((rand() % 1000) / 1000.0f) + 0.401);
            physics.setW(32);
            physics.setH(64);
            sprite.setSprite("assets/maul.png", 0, 0, 61, 64);
        }
        Maul::~Maul()
        {
            
        }

        void Maul::doDamage(Player *pl)
        {
            pl->takeDamage(darkness);
        }

        void Maul::update()
        {
            if (!isActive)
                return;

            if (health <= 0)
            {
                Deactivate();
                player->addScorePoints(10 + darkness);
            }
            move();
        }
        void Maul::save(ofstream &arq)
        {
            Physics *phy = this->getPhysics();
            arq << "3"
                << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << " " << phy->getXVelocity() << " " << phy->getYVelocity() << endl;
        }
    }
}