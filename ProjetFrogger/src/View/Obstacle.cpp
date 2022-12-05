#include "View/Obstacle.h"
#include <string>

using namespace std;
Obstacle::Obstacle(int type)
{
    shapeObstacle = RectangleShape({100,50}),
    textureObstacle.loadFromFile("Ressources/car"+to_string(type)+".png");
    shapeObstacle.setTexture(&textureObstacle);

    shapeObstacle.setPosition(0.f, 0.f);
}

Obstacle::~Obstacle()
{
    //dtor
}

RectangleShape& Obstacle::getGraphicEntity()
{

    return shapeObstacle;
}

void Obstacle::setRight(bool b)
{
    right = b;
}

bool Obstacle::isRight()
{

    return right;
}

