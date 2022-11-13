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
        Avatar* avatar;


    public:
        Joueur(int score=0,int vie=3);
        virtual ~Joueur();
        void augmenterScore(int score);
        string str();
        Avatar* getAvatar();
        int getVie()const;
        void looseLife();


};

#endif // JOUEUR_H
