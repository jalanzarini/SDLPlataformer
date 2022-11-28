#pragma once

#include "Projectile.hpp"
#include "Character.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace Characters
    {
        class Enemy : public Character
        {
        protected:
            bool shooter;
            Player* player;
            Player* player2;

        public:
            Enemy(int hp, Player* pl, Player* pl2, bool sh = false);
            ~Enemy();

            inline virtual Projectile* getBullet() {return nullptr;}
            inline const bool getIsShooter() const {return shooter;}
            
            inline virtual void doDamage(Player* pl) {pl->takeDamage();}

            virtual void update() = 0;
            inline virtual void save(ofstream &arq){}
        };
    }
}