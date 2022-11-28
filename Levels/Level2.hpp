#pragma once

#include "Level.hpp"

namespace Levels
{
    class Level2 : public Level
    {
    private:
        int maxTroopers;

    public:
        Level2(EventManager *ev, Player *player, Player *player2);
        ~Level2();

        Trooper* createTrooper(int x, int y);
        void trooperBulkInitialize();
        void spikeBulkInitialize();
        void barrelBulkInitialize();
        void vaderBulkInitialize();
        void initialize(Player *player, Player *player2, bool multi);

        void update();
        int load();
        void save();
    };
}