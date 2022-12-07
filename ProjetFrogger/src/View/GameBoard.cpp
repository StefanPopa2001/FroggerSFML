#include "View/GameBoard.h"

GameBoard::GameBoard()
{
    //texture des differents backgrounds
    shapeBoard = RectangleShape({700,900}),
    textureBoard.loadFromFile("Ressources/Plateau.png");
    shapeBoard.setTexture(&textureBoard);
    shapeBoard.setPosition(0.f, 0.f);

    loseForm = RectangleShape({700,900}),
    textureLose.loadFromFile("Ressources/lose.png");
    loseForm.setTexture(&textureLose);
    loseForm.setPosition(0.f, 0.f);

    winForm = RectangleShape({700,900}),
    textureWin.loadFromFile("Ressources/victory_screen.png");
    winForm.setTexture(&textureWin);
    winForm.setPosition(0.f, 0.f);

    //sert a determiner si le joueur a gagné ou perdu afin de changer l'ecran
    loose = false;
    win = false;
}

GameBoard::~GameBoard()
{
    //dtor
}

RectangleShape GameBoard::getGraphicEntityReplay(int nb)
{
    if(nb==1)//win
        return winForm;

    if (nb==2)//lose
        return loseForm;
    else
        return shapeBoard;

};

RectangleShape GameBoard::getGraphicEntity()
{
    if(win)//win
        return winForm;

    if (!loose)//lose
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




