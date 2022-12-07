#include "View/Avatar.h"
#include "View/Render.h"


Avatar::Avatar()
{
    shapeAvatar = RectangleShape({50,50}),
    textureAvatar.loadFromFile("Ressources/Avatar.png");
    shapeAvatar.setTexture(&textureAvatar);
    shapeAvatar.setPosition(0.f, 0.f);
}

Avatar::~Avatar()
{
    delete movingstate;
}

RectangleShape Avatar::getGraphicEntity()
{
    return shapeAvatar;
}

void Avatar::die()
{
     this->movingstate->setDeadState();
}

void Avatar::win()
{
    this->movingstate->setWinState();
}

void Avatar::replay()
{
    this->movingstate->setState();
}

void Avatar::putAvatarStartPosition()
{
    shapeAvatar.setPosition(300.f, 850.f);
}

//deplacement du joueur
void Avatar::moveAvatar(Event e)
{
    //gauche
    if (e.key.code == sf::Keyboard::Left)
    {

        vector<float> v = movingstate->getState()->getLeftMouvement();

        shapeAvatar.move(v[0],v[1]);

        if(shapeAvatar.getPosition().x < 0.f)
            shapeAvatar.setPosition(0.f , shapeAvatar.getPosition().y);
    }

    //droite
    else if (e.key.code == sf::Keyboard::Right)
    {

        vector<float> v = movingstate->getState()->getRightMouvement();

        shapeAvatar.move(v[0],v[1]);

        if(shapeAvatar.getPosition().x + shapeAvatar.getGlobalBounds().width > 700)
            shapeAvatar.setPosition(700 - shapeAvatar.getGlobalBounds().width, shapeAvatar.getPosition().y);
    }

    //haut
    else if (e.key.code == sf::Keyboard::Up)
    {

        vector<float> v = movingstate->getState()->getUptMouvement();
        shapeAvatar.move(v[0],v[1]);

        if(shapeAvatar.getPosition().y < 0.f)
            shapeAvatar.setPosition(shapeAvatar.getPosition().x , 0.f);

        if(shapeAvatar.getPosition().y < 150)
        {
            putAvatarStartPosition();
            Player::level++;
        }
    }
    //bas
    else if (e.key.code == sf::Keyboard::Down)
    {


        vector<float> v = movingstate->getState()->getDownMouvement();
        shapeAvatar.move(v[0],v[1]);

        if(shapeAvatar.getPosition().y + shapeAvatar.getGlobalBounds().height> 900)
            shapeAvatar.setPosition(shapeAvatar.getPosition().x , 900 - shapeAvatar.getGlobalBounds().height);
    }

}
