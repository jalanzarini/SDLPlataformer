#pragma once

#include "Ente.hpp"

#include "Physics.hpp"
using namespace Components;

#include <fstream>
#include <string>

namespace Entities
{
    class Entity : public Ente
    {
    private:
    protected:
        bool isActive;
        bool isGrounded;
        bool deletable;

        Physics physics;

        string type;

    public:
        Entity();
        ~Entity();

        inline void Deactivate() { isActive = false; }
        inline void Activate() { isActive = true; }
        inline const bool getIsActive() const { return isActive; }

        inline void setPhysics(int xPos, int yPos, int width, int height, int vX, int vY, int aX, int aY) { physics.setPhysics(xPos, yPos, width, height, vX, vY, aX, aY); }
        inline Physics *getPhysics() { return &physics; }

        inline const bool getDeletable() const { return deletable; }
        inline void setDeletable(bool b) { deletable = b; }

        inline void setIsGrounded(bool v) { isGrounded = v; }
        inline const bool getIsGrounded() const { return isGrounded; }

        inline const string getType() const { return type; }
        inline void setType(string t) { type = t; }

        void applyGravity();
        virtual void move();
        virtual void render();
        virtual void update() = 0;
        virtual void save(ofstream &arq) = 0;
    };
}