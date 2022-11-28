#include "Vader.hpp"

namespace Entities
{
    namespace Characters
    {
        Vader::Vader(Player *pl, Player *pl2) : Enemy(3, pl, pl2)
        {
            force = (rand() % 3) + 3;
            sprite.setSprite("assets/vader.png", 0, 0, 64, 51, 1);
            physics.setXVelocity(((rand() % 1000) / 1000.0f) + 1.301);
            physics.setW(64 * sprite.getMultiplier());
            physics.setH(51 * sprite.getMultiplier());
        }
        Vader::~Vader()
        {

        }

        void Vader::doDamage(Player *pl)
        {
            pl->takeDamage(force);
        }

        void Vader::update()
        {
            if (!isActive)
                return;

            if (health <= 0)
            {
                Deactivate();
                player->addScorePoints(50 + force);
            }
            move();
        }
        void Vader::save(ofstream &arq)
        {
            Physics *phy = this->getPhysics();
            arq << "4"
                << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << " " << phy->getXVelocity() << " " << phy->getYVelocity() << endl;
        }
    }
}