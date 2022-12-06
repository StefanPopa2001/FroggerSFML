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

    winForm = RectangleShape({700,900}),
    textureWin.loadFromFile("Ressources/victory_screen.jfif");
    winForm.setTexture(&textureWin);
    winForm.setPosition(0.f, 0.f);

    loose = false;
    win = false;
}

GameBoard::~GameBoard()
{
    //dtor
}

RectangleShape GameBoard::getGraphicEntity()
{
    if(win)
        return winForm;

    if (!loose)
        return shapeBoard;
    else
        return loseForm;

};

void GameBoard::setLose(bool lose)
{
    this->loose = lose;
}

void GameBoard::setWin(bool win)
{
    this->win = win;
}

bool GameBoard::isWin()
{
    return win;
}

bool GameBoard::isLoose()
{
    return loose;
}




