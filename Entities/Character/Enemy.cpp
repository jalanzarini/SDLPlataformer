#include "Enemy.hpp"
using namespace Entities;
using namespace Characters;

Enemy::Enemy(int hp, Player* pl, Player* pl2, bool sh) : Character(hp), player(pl), player2(pl2), shooter(sh)
{
    type = "Enemy";
}

Enemy::~Enemy()
{

}