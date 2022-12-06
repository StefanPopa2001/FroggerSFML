#ifndef PLATEAU_H
#define PLATEAU_H

#include <SFML/Graphics.hpp>

using namespace sf;

class GameBoard
{
    private:
        RectangleShape shapeBoard;
        Texture textureBoard;

        RectangleShape loseForm;
        Texture textureLose;

        RectangleShape winForm;
        Texture textureWin;

        bool loose;
        bool win;

    public:
        GameBoard();
        virtual ~GameBoard();
        RectangleShape getGraphicEntity();
        RectangleShape getGraphicEntityReplay(int nbr);
        void setLose(bool lose);
        bool isLoose();
        void setWin(bool win);
        bool isWin();


};

#endif // JOUEUR_H
