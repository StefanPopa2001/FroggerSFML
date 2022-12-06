#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <View/Avatar.h>

using namespace std;

class Player
{

    private:
        int score;
        int life;
        int nbPoints;
        Avatar* avatar;



    public:
        Player(int score=0,int life=3, int nbPoints=0);
        virtual ~Player();
        void upScore(int score);
        string str();
        Avatar* getAvatar();
        int getLife()const;
        int getNbPoints()const;
        void looseLife();
        int getLevel()const;

        void setLevel(int level);
        void setLife(int life);
        void setNbPoints(int points);


        inline static int level = 1;

        void winPoint();


};

#endif // JOUEUR_H
