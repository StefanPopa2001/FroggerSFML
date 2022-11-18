#include "Beer.h"

Beer::Beer()
{
    lifeForm = RectangleShape({50,50}),
    lifeTexture.loadFromFile("Ressources/beer.png");
    lifeForm.setTexture(&lifeTexture);
    lifeForm.setPosition(0.f, 0.f);
}

Beer::~Beer()
{
    //dtor
}

Beer::Beer(const Beer& other)
{
    //copy ctor
}

Beer& Beer::operator=(const Beer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

RectangleShape& Beer::getShape()
{

    return lifeForm;
}
