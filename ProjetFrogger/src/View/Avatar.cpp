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
        formeAvatar.move(-50,0);

        if(formeAvatar.getPosition().x < 0.f)
            formeAvatar.setPosition(0.f , formeAvatar.getPosition().y);
    }

    else if (e.key.code == sf::Keyboard::Right)
    {
        formeAvatar.move(50,0);

        if(formeAvatar.getPosition().x + formeAvatar.getGlobalBounds().width > 700)
            formeAvatar.setPosition(700 - formeAvatar.getGlobalBounds().width, formeAvatar.getPosition().y);
    }

    else if (e.key.code == sf::Keyboard::Up)
    {
        formeAvatar.move(0,-50);

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
        formeAvatar.move(0,50);
        if(formeAvatar.getPosition().y + formeAvatar.getGlobalBounds().height> 900)
            formeAvatar.setPosition(formeAvatar.getPosition().x , 900 - formeAvatar.getGlobalBounds().height);
    }


}
