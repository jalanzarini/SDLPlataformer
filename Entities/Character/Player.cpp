#include "Player.hpp"
using namespace Entities;
using namespace Characters;

int Player::points = 0;

Player::Player() : Character(10), bullet(new Projectile(true))
{
    type = "Player";
    physics.setH(64);
    physics.setW(44);
    bullet->setDeletable(false);
}

Player::~Player()
{
    event = nullptr;
    delete bullet;
}

void Player::reset()
{
    points = 0;
    Activate();
    health = 10;
}

void Player::setInputSystem(EventManager *ev, SDL_Scancode l, SDL_Scancode r, SDL_Scancode j, SDL_Scancode f)
{
    event = ev;
    input.setCharacterInput(l, r, j, f);
}

void Player::update()
{
    if (!isActive)
        return;

    if (health <= 0)
    {
        Deactivate();
    }

    physics.setXVelocity(0);

    if (event->getKeyDown(input.getLeft()))
    {
        physics.setMoveDirection(-1);
        physics.setXVelocity(-6);
    }
    if (event->getKeyDown(input.getRight()))
    {
        physics.setMoveDirection(1);
        physics.setXVelocity(6);
    }
    if (event->getKeyDown(input.getJump()))
    {
        if (getIsGrounded())
            physics.setYVelocity(-37);
    }
    if (event->getKeyDown(input.getFire()))
    {
        bullet->fire(physics.getXPosition() - physics.getMoveDirection() * 15, physics.getYPosition() + 25, physics.getMoveDirection());
    }
    move();
    setIsGrounded(false);
}

void Player::save(ofstream &arq)
{
    Physics *phy = this->getPhysics();
    arq << (this->getType() == "Player1" ? 10 : 11) << " " << (this->getIsActive() ? 1 : 0) << " " << this->getHealth() << " " << this->getScorePoints() << " " << phy->getXPosition() << " " << phy->getYPosition() - phy->getYVelocity()-5 << " " << phy->getXVelocity() << " " << phy->getYVelocity() << endl;
}