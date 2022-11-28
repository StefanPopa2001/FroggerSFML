#include "View/GameBoard.h"

GameBoard::GameBoard()
{
    shapeBoard = RectangleShape({700,900}),
    textureBoard.loadFromFile("Ressources/Plateau.png");
    shapeBoard.setTexture(&textureBoard);
    shapeBoard.setPosition(0.f, 0.f);

    loseForm = RectangleShape({700,900}),
    textureLose.loadFromFile("Ressources/lose.png");
    loseForm.setTexture(&textureLose);
    loseForm.setPosition(0.f, 0.f);

    loose = false;
}

GameBoard::~GameBoard()
{
    //dtor
}

RectangleShape GameBoard::getGraphicEntity()
{
    if (!loose)
        return shapeBoard;
    else
        return loseForm;

};

void GameBoard::setLose(bool lose)
{
    this->loose = lose;
}

bool GameBoard::isLoose()
{
    return loose;
}




