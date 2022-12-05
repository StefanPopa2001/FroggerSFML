#ifndef Voiture_H
#define Voiture_H
#include <string>
#include <Model/Car.h>
#include <View/Obstacle.h>

using namespace std;

class Car
{

    private:
        int type;
        Obstacle* obstacle;

    public:
        Car(int type=rand()%3+1);
        virtual ~Car();
        Obstacle& getObstacle();
        void moove(int direction);
};

#endif // JOUEUR_H
