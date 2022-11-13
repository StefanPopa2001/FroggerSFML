#include "Model/Joueur.h"
#include <SFML/Graphics.hpp>

Joueur::Joueur(int score,int vie):score(score),vie(vie)
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

void Joueur::looseLife()
{
    vie--;
}
