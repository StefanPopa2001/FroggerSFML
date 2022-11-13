#include "Life.h"

Life::Life()
{
    lifeForm = RectangleShape({50,50}),
    lifeTexture.loadFromFile("Ressources/life.png");
    lifeForm.setTexture(&lifeTexture);
    lifeForm.setPosition(0.f, 0.f);
}

Life::~Life()
{
    //dtor
}

Life::Life(const Life& other)
{
    //copy ctor
}

Life& Life::operator=(const Life& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

RectangleShape& Life::getShape()
{

    return lifeForm;
}
