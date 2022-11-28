#include "Level1.hpp"

namespace Levels
{
    Level1::Level1(EventManager *ev, Player *player, Player *player2) : Level(ev)
    {
        p1 = player;
        p2 = player2;
        maxMauls = 5;

        sprite.setSprite("assets/back.png", 0, 0, 1920, 1080);
        groundInitialize();
    }
    Level1::~Level1()
    {
        cout << "Level1 Destroyed" << endl;
    }

    Maul *Level1::createMaul(int x, int y)
    {
        Maul *maul = new Maul(p1, p2);
        maul->getPhysics()->setPosition(x, y);
        entList.insert(static_cast<Entity *>(maul));
        colManager.insertEnemy(static_cast<Enemy *>(maul));
        return maul;
    }

    void Level1::maulBulkInitialize()
    {
        int cont = maxMauls;
        createMaul(rand() % (720 - 360) + 360, 970);
        cont--;
        if (rand() % 3 == 0)
        {
            createMaul(rand() % (720 - 360) + 360, 970);
            cont--;
        }
        createMaul(rand() % (1500 - 1210) + 1210, 970);
        cont--;
        while (cont > 0)
        {
            createMaul(rand() % (1030 - 780) + 780, 970);
            cont--;
        }
    }

    void Level1::spikeBulkInitialize()
    {
        createSpike(rand() % (1235 - 1161) + 1161, 790);
        createSpike(rand() % (1030 - 360) + 360, 1000);
        if (rand() % 3 == 0)
            createSpike(rand() % (1830 - 1210) + 1210, 1000);
        createSpike(rand() % (325 - 228) + 228, 710);
    }

    void Level1::barrelBulkInitialize()
    {
        createBarrel(rand() % (720 - 360) + 360, 970);
        createBarrel(45, 760);
        if (rand() % 3 == 0)
            createBarrel(rand() % (1030 - 784) + 784, 970);
        createBarrel(rand() % (1830 - 1210) + 1210, 970);
    }

    void Level1::vaderBulkInitialize()
    {
        createVader(rand() % (1500 - 1210) + 1210, 970);
        createVader(rand() % (1500 - 1210) + 1210, 970);
        createVader(rand() % (1030 - 780) + 780, 970);
    }

    void Level1::initialize(Player *player, Player *player2, bool multi)
    {
        cout << "Level1 Initialized" << endl;
        entList.insert(static_cast<Entity *>(gnd));

        //------------------------------------------------------------------------
        // Player initialize

        player->getPhysics()->setPosition(50, 950);
        entList.insert(static_cast<Entity *>(player));
        entList.insert(static_cast<Entity *>(player->getBullet()));
        colManager.setPlayer(player);

        player2->getPhysics()->setPosition(150, 950);
        entList.insert(static_cast<Entity *>(player2));
        entList.insert(static_cast<Entity *>(player2->getBullet()));
        colManager.setPlayer2(player2);

        player2->Activate();
        if (!multi)
            player2->Deactivate();

        //-------------------------------------------------------------------------
        // Enemy Initialize

        vaderBulkInitialize();
        maulBulkInitialize();

        //-------------------------------------------------------------------------
        // Obstacles Initialize

        barrelBulkInitialize();
        spikeBulkInitialize();

        //"Static" plataforms

        for (int i = 7; i > 0; i--)
            createPlataform(0, 830 - i * 45, 3);
        createPlataform(0, 830, 2);
        for (int i = 4; i > 0; i--)
        {
            createPlataform(0, GraphicManager::getInstance()->getHeight() - 45 - i * 45, 3);
            createPlataform(GraphicManager::getInstance()->getWidth() - 43, GraphicManager::getInstance()->getHeight() - 45 - i * 45, 3);
        }

        createPlataform(228, 735, 2);
        for (int i = 5; i > 0; i--)
            createPlataform(314, 990 - i * 45, 3);
        createPlataform(271, 900, 5);
        createPlataform(271, 945, 3);
        createPlataform(228, 900, 5);
        createPlataform(228, 945, 3);
        createPlataform(185, 990, 5);
        createPlataform(228, 990);

        createPlataform(1161, 850, 2);
        for (int i = 3; i > 0; i--)
            createPlataform(1161, 990 - i * 45, 3);
        createPlataform(1117, 945, 5);
        createPlataform(1075, 990);
    }

    int Level1::load()
    {

        ifstream arq;
        arq.open("da.txt", ios::in);

        entList.insert(static_cast<Entity *>(gnd));
        int lvlnum;

        int id, active;
        float x, y;
        float vx, vy;
        int hp;

        int bid;
        int bActive;
        int bx, by;
        int bvx, bvy;
        int type;
        int points;

        Maul *maul = nullptr;
        Vader *vader = nullptr;

        arq >> lvlnum;

        while (!arq.eof())
        {
            arq >> id;

            switch (id)
            {
            case 3:
                arq >> active;
                arq >> x >> y;
                arq >> vx >> vy;
                maul = createMaul(x, y);
                maul->getPhysics()->setVelocity(vx, vy);
                maul->Deactivate();
                if (active)
                {
                    maul->Activate();
                }
                break;
            case 4:
                arq >> active;
                arq >> x >> y;
                arq >> vx >> vy;
                vader = createVader(x, y);
                vader->getPhysics()->setVelocity(vx, vy);
                vader->Deactivate();
                if (active)
                {
                    vader->Activate();
                }
                break;
            case 5:
                arq >> active;
                arq >> x;
                arq >> y;
                createBarrel(x, y);
                break;
            case 6:
                arq >> active;
                arq >> x;
                arq >> y;
                createSpike(x, y);
                break;
            case 7:
                arq >> type;
                arq >> active;
                arq >> x;
                arq >> y;
                createPlataform(x, y, type);
                break;
            case 10:
                arq >> active;
                arq >> hp;
                arq >> points;
                arq >> x >> y;
                arq >> vx >> vy;

                arq >> bid;
                arq >> bActive;
                arq >> bx >> by;
                arq >> bvx >> bvy;

                p1->setHealth(hp);
                p1->addScorePoints(points);
                p1->getPhysics()->setPosition(x, y);
                p1->getPhysics()->setVelocity(vx, vy);

                p1->getBullet()->getPhysics()->setPosition(bx, by);
                p1->getBullet()->getPhysics()->setVelocity(bvx, bvy);

                p1->getBullet()->Deactivate();
                if (bActive)
                {
                    p1->getBullet()->Activate();
                }

                entList.insert(static_cast<Entity *>(p1));
                entList.insert(static_cast<Entity *>(p1->getBullet()));
                colManager.setPlayer(p1);
                p1->Deactivate();
                if (active)
                {
                    p1->Activate();
                }
                break;
            case 11:
                arq >> active;
                arq >> hp;
                arq >> points;
                arq >> x >> y;
                arq >> vx >> vy;

                arq >> bid;
                arq >> bActive;
                arq >> bx >> by;
                arq >> bvx >> bvy;

                p2->setHealth(hp);
                p2->getPhysics()->setPosition(x, y);
                p2->getPhysics()->setVelocity(vx, vy);

                p2->Deactivate();
                if (active)
                {
                    p2->Activate();
                }

                p2->getBullet()->getPhysics()->setPosition(bx, by);
                p2->getBullet()->getPhysics()->setVelocity(bvx, bvy);

                p2->getBullet()->Deactivate();
                if (bActive)
                {
                    p2->getBullet()->Activate();
                }

                entList.insert(static_cast<Entity *>(p2));
                entList.insert(static_cast<Entity *>(p2->getBullet()));
                colManager.setPlayer2(p2);

                break;

            default:
                break;
            }
        }

        arq.close();
        if (p1 == nullptr)
            return 0;
        return lvlnum;
    }

    void Level1::update()
    {
        gnd->render();
        colManager.Execute();
        entList.updateAll();
        Score.update("Points: " + to_string(Player::getScorePoints()));
        p1Life.update("HP: " + to_string(p1->getHealth()));
        p2Life.update("HP: " + to_string(p2->getHealth()));
    }

    void Level1::save()
    {
        entList.save("da.txt", 1);
    }
}