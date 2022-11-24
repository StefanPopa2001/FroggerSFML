#ifndef AVATAR_H
#define AVATAR_H

#include <SFML/Graphics.hpp>
#include <MovingState.h>
#include <MovingStateAlive.h>
#include <MovingStateDead.h>
#include <MovingStateWin.h>
#include <ContextMovingState.h>

using namespace sf;

class Avatar
{
    private:
        RectangleShape formeAvatar;
        Texture textureAvatar;
        ContextMovingState* movingstate = new ContextMovingState;

    public:
        void die(){
            this->movingstate->setDeadState();
        }
        Avatar();
        virtual ~Avatar();
        RectangleShape getEntiteGraphique();
        void mettreAvatarPositionDepart();
        void deplacerAvatar(Event e);


};

#endif // JOUEUR_H
