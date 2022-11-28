#pragma once

#include <SDL2/SDL.h>

namespace Components
{
    class CharacterInput
    {
    private:
        SDL_Scancode left;
        SDL_Scancode right;
        SDL_Scancode jump;
        SDL_Scancode fire;

    public:
        CharacterInput() : left(SDL_SCANCODE_A), right(SDL_SCANCODE_D), jump(SDL_SCANCODE_SPACE), fire(SDL_SCANCODE_Q){};
        ~CharacterInput(){};

        void setCharacterInput(SDL_Scancode l, SDL_Scancode r, SDL_Scancode j, SDL_Scancode f)
        {
            setLeft(l);
            setRight(r);
            setJump(j);
            setFire(f);
        }

        inline const SDL_Scancode getLeft() const {return left;}
        inline const SDL_Scancode getRight() const { return right; }
        inline const SDL_Scancode getJump() const { return jump; }
        inline const SDL_Scancode getFire() const { return fire; }

        inline void setLeft(SDL_Scancode l) { left = l; }
        inline void setRight(SDL_Scancode r) { right = r; }
        inline void setJump(SDL_Scancode j) { jump = j; }
        inline void setFire(SDL_Scancode f) { fire = f; }
    };
}