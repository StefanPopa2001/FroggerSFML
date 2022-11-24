#include "View/Avatar.h"
#include "View/Rendu.h"


Avatar::Avatar()
{
    formeAvatar = RectangleShape({50,50}),
    textureAvatar.loadFromFile("Ressources/Avatar.png");
    formeAvatar.setTexture(&textureAvatar);
    formeAvatar.setPosition(0.f, 0.f);
}

Avatar::~Avatar()
{
    //dtor
}

RectangleShape Avatar::getEntiteGraphique()
{
    return formeAvatar;
}

void Avatar::mettreAvatarPositionDepart()
{
    formeAvatar.setPosition(300.f, 850.f);
}

//todo ==> la taille de l'écran est hard codée, il faudrait la prendre d'une autre manière
void Avatar::deplacerAvatar(Event e)
{



    if (e.key.code == sf::Keyboard::Left)
    {

        vector<float> v = movingstate->getState()->getLeftMouvement();

        formeAvatar.move(v[0],v[1]);

        if(formeAvatar.getPosition().x < 0.f)
            formeAvatar.setPosition(0.f , formeAvatar.getPosition().y);
    }

    else if (e.key.code == sf::Keyboard::Right)
    {

        vector<float> v = movingstate->getState()->getRightMouvement();

        formeAvatar.move(v[0],v[1]);

        if(formeAvatar.getPosition().x + formeAvatar.getGlobalBounds().width > 700)
            formeAvatar.setPosition(700 - formeAvatar.getGlobalBounds().width, formeAvatar.getPosition().y);
    }

    else if (e.key.code == sf::Keyboard::Up)
    {

        vector<float> v = movingstate->getState()->getUptMouvement();
        formeAvatar.move(v[0],v[1]);

        if(formeAvatar.getPosition().y < 0.f)
            formeAvatar.setPosition(formeAvatar.getPosition().x , 0.f);

        if(formeAvatar.getPosition().y < 150)
        {
            mettreAvatarPositionDepart();
            Joueur::level++;
        }


    }

    else if (e.key.code == sf::Keyboard::Down)
    {


        vector<float> v = movingstate->getState()->getDownMouvement();
        formeAvatar.move(v[0],v[1]);

        if(formeAvatar.getPosition().y + formeAvatar.getGlobalBounds().height> 900)
            formeAvatar.setPosition(formeAvatar.getPosition().x , 900 - formeAvatar.getGlobalBounds().height);
    }


}
