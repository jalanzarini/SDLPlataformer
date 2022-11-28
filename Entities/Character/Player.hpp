#pragma once

#include "Character.hpp"

#include "EventManager.hpp"
using namespace Managers;

#include "CharacterInput.hpp"
using namespace Components;

#include "Projectile.hpp"

namespace Entities
{
    namespace Characters
    {
        class Player : public Character
        {
        private:
            EventManager *event;
            CharacterInput input;

            Projectile *bullet;

            static int points;

        public:
            Player();
            ~Player();

            void reset();

            inline static void addScorePoints(int i) { points += i; }
            inline static int getScorePoints() { return points; }

            void setInputSystem(EventManager *ev, SDL_Scancode l, SDL_Scancode r, SDL_Scancode j, SDL_Scancode f);
            inline const CharacterInput getInputSystem() const { return input; }

            inline Projectile *getBullet() { return bullet; }

            void update();
            void save(ofstream &arq);
        };
    }
}