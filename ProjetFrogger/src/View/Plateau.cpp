#include "View/Plateau.h"

Plateau::Plateau()
{
    formePlateau = RectangleShape({700,900}),
    texturePlateau.loadFromFile("Ressources/Plateau.png");
    formePlateau.setTexture(&texturePlateau);
    formePlateau.setPosition(0.f, 0.f);
}

Plateau::~Plateau()
{
    //dtor
}

RectangleShape Plateau::getEntiteGraphique()
{
    return formePlateau;
};
