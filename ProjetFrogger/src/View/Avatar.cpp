#include "View/Avatar.h"
#include "View/Rendu.h"


Avatar::Avatar()
{
    shapeAvatar = RectangleShape({50,50}),
    textureAvatar.loadFromFile("Ressources/Avatar.png");
    shapeAvatar.setTexture(&textureAvatar);
    shapeAvatar.setPosition(0.f, 0.f);
}

Avatar::~Avatar()
{
    //dtor
}

RectangleShape Avatar::getGraphicEntity()
{
    return shapeAvatar;
}

void Avatar::putAvatarStartPosition()
{
    shapeAvatar.setPosition(300.f, 850.f);
}

//todo ==> la taille de l'écran est hard codée, il faudrait la prendre d'une autre manière
void Avatar::moveAvatar(Event e)
{



    if (e.key.code == sf::Keyboard::Left)
    {

        vector<float> v = movingstate->getState()->getLeftMouvement();

        shapeAvatar.move(v[0],v[1]);

        if(shapeAvatar.getPosition().x < 0.f)
            shapeAvatar.setPosition(0.f , shapeAvatar.getPosition().y);
    }

    else if (e.key.code == sf::Keyboard::Right)
    {

        vector<float> v = movingstate->getState()->getRightMouvement();

        shapeAvatar.move(v[0],v[1]);

        if(shapeAvatar.getPosition().x + shapeAvatar.getGlobalBounds().width > 700)
            shapeAvatar.setPosition(700 - shapeAvatar.getGlobalBounds().width, shapeAvatar.getPosition().y);
    }

    else if (e.key.code == sf::Keyboard::Up)
    {

        vector<float> v = movingstate->getState()->getUptMouvement();
        shapeAvatar.move(v[0],v[1]);

        if(shapeAvatar.getPosition().y < 0.f)
            shapeAvatar.setPosition(shapeAvatar.getPosition().x , 0.f);

        if(shapeAvatar.getPosition().y < 150)
        {
            putAvatarStartPosition();
            Joueur::level++;
        }


    }

    else if (e.key.code == sf::Keyboard::Down)
    {


        vector<float> v = movingstate->getState()->getDownMouvement();
        shapeAvatar.move(v[0],v[1]);

        if(shapeAvatar.getPosition().y + shapeAvatar.getGlobalBounds().height> 900)
            shapeAvatar.setPosition(shapeAvatar.getPosition().x , 900 - shapeAvatar.getGlobalBounds().height);
    }


}
