#include "View/Plateau.h"

Plateau::Plateau()
{
    formePlateau = RectangleShape({700,900}),
    texturePlateau.loadFromFile("Ressources/Plateau.png");
    formePlateau.setTexture(&texturePlateau);
    formePlateau.setPosition(0.f, 0.f);

    loseForm = RectangleShape({700,900}),
    textureLose.loadFromFile("Ressources/lose.png");
    loseForm.setTexture(&textureLose);
    loseForm.setPosition(0.f, 0.f);

    loose = false;
}

Plateau::~Plateau()
{
    //dtor
}

RectangleShape Plateau::getEntiteGraphique()
{
    if (!loose)
        return formePlateau;
    else
        return loseForm;

};

void Plateau::setLose(bool lose)
{
    this->loose = lose;
}

bool Plateau::isLoose()
{
    return loose;
}




