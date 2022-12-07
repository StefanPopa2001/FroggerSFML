#include "Model/Player.h"
#include <SFML/Graphics.hpp>

//le joueur possede un avatar, si le jouer meurt, l'avatar aussi
Player::Player(int score,int life, int nbPoints):score(score),life(life),nbPoints(nbPoints)
{
    Player::avatar = new Avatar();
}

Player::~Player()
{
    delete Player::avatar;
}


void Player::upScore(int score)
{
    Player::score+=score;
}

string Player::str()
{
    return "Score : "+to_string(score)+"\t Vies : "+to_string(life);
}


Avatar* Player::getAvatar()
{
    return avatar;
}

int Player::getLife()const
{
    return life;
}
int Player::getNbPoints()const
{
    return nbPoints;
}

void Player::looseLife()
{
    life--;
}

void Player::winPoint()
{
    nbPoints++;
}

int Player::getLevel()const
{
    return Player::level;
}

void Player::setLevel(int levell)
{
    level=levell;
}

void Player::setNbPoints(int points)
{
    nbPoints=points;
}

void Player::setLife(int lifes)
{
    life=lifes;
}
