#include "Model/Car.h"
#include <SFML/Graphics.hpp>

Car::Car(int type):type(type)
{
    Car::obstacle = new Obstacle(type);
}

Car::~Car()
{
    delete Car::obstacle;
}

Obstacle& Car::getObstacle()
{
    return *obstacle;
}

// 1 = gauche � droite
// -1 = droite � gauche
void Car::moove(int direction)
{
    //getObstacle().getEntiteGraphique().scale(sens,1);

    getObstacle().getGraphicEntity().move((1*type+1)*direction,0);
}
