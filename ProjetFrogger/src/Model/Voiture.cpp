#include "Model/Voiture.h"
#include <SFML/Graphics.hpp>

Voiture::Voiture(int type):type(type)
{
    Voiture::obstacle = new Obstacle(type);
}

Voiture::~Voiture()
{
    delete Voiture::obstacle;
}

Obstacle& Voiture::getObstacle()
{
    return *obstacle;
}

// 1 = gauche � droite
// -1 = droite � gauche
void Voiture::deplacer(int sens)
{
    getObstacle().getEntiteGraphique().scale(sens,1);
    getObstacle().getEntiteGraphique().move(1*type+1,1);
}
