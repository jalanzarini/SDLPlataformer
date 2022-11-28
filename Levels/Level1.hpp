#pragma once

#include "Level.hpp"

#include <fstream>
using namespace std;

namespace Levels
{
    class Level1 : public Level
    {
    private:
        int maxMauls;

    public:
        Level1(EventManager *ev, Player *player, Player *player2);
        ~Level1();

        Maul* createMaul(int x, int y);
        void maulBulkInitialize();
        void spikeBulkInitialize();
        void barrelBulkInitialize();
        void vaderBulkInitialize();
        
        void initialize(Player *player, Player *player2, bool multi);
        
        void update();
        int load();
        void save();
    };
}