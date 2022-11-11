#ifndef RENDU_H
#define RENDU_H

#include <vector>
#include "Model/Voiture.h"
#include "Model/Joueur.h"
#include "View/Plateau.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Rendu
{
    private:
        vector<Voiture*> voitures;
        Joueur* joueur;

        Voiture v;
        Plateau plateau;

    public:
        Rendu();
        virtual ~Rendu();
        int afficherJeu();

        inline static int compteurPosY = 150;


};

#endif // JOUEUR_H
