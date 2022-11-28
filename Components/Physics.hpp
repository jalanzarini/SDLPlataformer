#pragma once

#include <SDL2/SDL.h>

namespace Components
{
    class Physics
    {
    private:
        float xPosition, yPosition;
        float xVelocity, yVelocity;
        float xAcceleration, yAcceleration;
        int moveDir;

        int w;
        int h;

    public:
        Physics() : xPosition(0), yPosition(0), xVelocity(0), yVelocity(0), xAcceleration(0), yAcceleration(0), w(0), h(0), moveDir(1)
        {

        }
        ~Physics()
        {
            
        }

        void setPhysics(int xPos, int yPos, int width, int height, int xVel, int yVel, int xAcc, int yAcc)
        {
            setPosition(xPos, yPos);
            setVelocity(xVel, yVel);
            setAcceleration(xAcc, yAcc);

            setW(width);
            setH(height);
        }

        inline const int getMoveDirection() const { return moveDir; }
        inline void setMoveDirection(int dir) { moveDir = dir; }

        inline const float getXPosition() const { return xPosition; }
        inline const float getYPosition() const { return yPosition; }
        inline const float getXVelocity() const { return xVelocity; }
        inline const float getYVelocity() const { return yVelocity; }
        inline const float getXAcceleration() const { return xAcceleration; }
        inline const float getYAcceleration() const { return yAcceleration; }
        inline const int getW() const { return w; }
        inline const int getH() const { return h; }

        void setPosition(float x, float y)
        {
            xPosition = x;
            yPosition = y;
        }

        inline void setXPosition(float x) { xPosition = x; }
        inline void setYPosition(float y) { yPosition = y; }

        void setVelocity(float x, float y)
        {
            xVelocity = x;
            yVelocity = y;
            moveDir = (x > 0) ? 1 : -1;
        }

        inline void setXVelocity(float x) { xVelocity = x; }
        inline void setYVelocity(float y) { yVelocity = y; }

        void setAcceleration(float x, float y)
        {
            xAcceleration = x;
            yAcceleration = y;
        }

        inline void setXAcceleration(float x) { xAcceleration = x; }
        inline void setYAcceleration(float y) { yAcceleration = y; }

        inline void setW(int width) { w = width; }
        inline void setH(int height) { h = height; }
    };
}
