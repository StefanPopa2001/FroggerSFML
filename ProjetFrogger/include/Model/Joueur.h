#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <View/Avatar.h>

using namespace std;

class Joueur
{

    private:
        int score;
        int vie;
        int nbPoints;
        Avatar* avatar;



    public:
        Joueur(int score=0,int vie=3, int nbPoints=0);
        virtual ~Joueur();
        void augmenterScore(int score);
        string str();
        Avatar* getAvatar();
        int getVie()const;
        int getNbPoints()const;
        void looseLife();
        int getLevel()const;

        inline static int level = 1;

        void winPoint();


};

#endif // JOUEUR_H
