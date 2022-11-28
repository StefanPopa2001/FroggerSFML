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


        bool loose;

    public:
        GameBoard();
        virtual ~GameBoard();
        RectangleShape getGraphicEntity();
        void setLose(bool lose);
        bool isLoose();



};

#endif // JOUEUR_H
