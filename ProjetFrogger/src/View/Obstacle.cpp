#include "View/Obstacle.h"
#include <string>

using namespace std;

Obstacle::Obstacle(int type)
{
    formeObstacle = RectangleShape({100,50}),
    textureObstacle.loadFromFile("Ressources/car"+to_string(type)+".png");
    formeObstacle.setTexture(&textureObstacle);
    formeObstacle.setPosition(0.f, 0.f);
}

Obstacle::~Obstacle()
{
    //dtor
}

RectangleShape& Obstacle::getEntiteGraphique()
{

    return formeObstacle;
}

