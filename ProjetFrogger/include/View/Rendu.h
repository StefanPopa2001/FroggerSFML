#ifndef RENDU_H
#define RENDU_H

#include <vector>
#include "Model/Car.h"
#include "Model/Player.h"
#include "View/GameBoard.h"
#include "View/Life.h"
#include "View/Beer.h"
#include "View/menuEndGame.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Rendu
{
    private:
        vector<Car*> cars;
        Player* player;
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
        int showGame();

        inline static int compteurPosY = 150;


};

#endif // JOUEUR_H
