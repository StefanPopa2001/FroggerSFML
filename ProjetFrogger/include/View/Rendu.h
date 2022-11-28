#ifndef RENDU_H
#define RENDU_H

#include <vector>
#include "Model/Voiture.h"
#include "Model/Joueur.h"
#include "View/GameBoard.h"
#include "View/Life.h"
#include "View/Beer.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Rendu
{
    private:
        vector<Voiture*> cars;
        Joueur* player;
        vector<Life*> lifes;
        vector<Beer*> beers;

        Text level;
        Text score;
        Text gameEnd;
        Font font;
        GameBoard board;

    public:
        Rendu();
        virtual ~Rendu();
        int afficherJeu();

        inline static int compteurPosY = 150;


};

#endif // JOUEUR_H
