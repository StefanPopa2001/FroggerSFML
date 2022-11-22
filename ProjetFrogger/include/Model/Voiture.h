#ifndef Voiture_H
#define Voiture_H
#include <string>
#include <Model/Voiture.h>
#include <View/Obstacle.h>

using namespace std;

class Voiture
{

    private:
        int type;
        Obstacle* obstacle;

    public:
        Voiture(int type=rand()%3+1);
        virtual ~Voiture();
        Obstacle& getObstacle();
        void deplacer(int sens);
};

#endif // JOUEUR_H
