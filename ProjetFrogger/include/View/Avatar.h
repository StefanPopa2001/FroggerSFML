#ifndef AVATAR_H
#define AVATAR_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Avatar
{
    private:
        RectangleShape formeAvatar;
        Texture textureAvatar;

    public:
        Avatar();
        virtual ~Avatar();
        RectangleShape getEntiteGraphique();
        void mettreAvatarPositionDepart();
        void deplacerAvatar(Event e);


};

#endif // JOUEUR_H
