#include "Model/Joueur.h"
#include <SFML/Graphics.hpp>

Joueur::Joueur(int score,int vie, int nbPoints):score(score),vie(vie),nbPoints(nbPoints)
{
    Joueur::avatar = new Avatar();
}

Joueur::~Joueur()
{
    delete Joueur::avatar;
}



void Joueur::augmenterScore(int score)
{
    Joueur::score+=score;
}

string Joueur::str()
{
    return "Score : "+to_string(score)+"\t Vies : "+to_string(vie);
}


Avatar* Joueur::getAvatar()
{
    return avatar;
}

int Joueur::getVie()const
{
    return vie;
}
int Joueur::getNbPoints()const
{
    return nbPoints;
}

void Joueur::looseLife()
{
    vie--;
}

void Joueur::winPoint()
{
    nbPoints++;
}

int Joueur::getLevel()const
{
    return Joueur::level;
}
