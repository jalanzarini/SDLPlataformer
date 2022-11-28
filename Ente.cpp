#include "Ente.hpp"

#include <iostream>

GraphicManager *Ente::gfx = GraphicManager::getInstance();
int Ente::enteSize = 0;

Ente::Ente()
{
    enteSize++; //Update Number of Entes
    id = enteSize; //Set Ente ID

    cout << "Ente Created! id: " << id << endl;
}

Ente::~Ente()
{
    gfx = nullptr; //Unset Pointer to Graphic Manager

    cout << "Ente Destroyed! id: " << id << endl;
}

void Ente::setSprite(string p, int f, int c, int w, int h, int m)
{
    sprite.setSprite(p, f, c, w, h, m); //Creates Sprite Component
}