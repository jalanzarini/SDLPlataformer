#include "Entity.hpp"
using namespace Entities;

Entity::Entity() : isActive(true), isGrounded(false), deletable(true)
{

}

Entity::~Entity()
{
}

void Entity::applyGravity()
{
    physics.setYAcceleration(5);
}

void Entity::move()
{
    applyGravity();

    physics.setYVelocity(physics.getYVelocity() + physics.getYAcceleration());
    if (physics.getYVelocity() > 10)
        physics.setYVelocity(10);

    physics.setXPosition(physics.getXPosition() + physics.getXVelocity());
    physics.setYPosition(physics.getYPosition() + physics.getYVelocity());
}

void Entity::render()
{
    if (isActive)
        sprite.render(physics.getXPosition(), physics.getYPosition(), physics.getMoveDirection());
}