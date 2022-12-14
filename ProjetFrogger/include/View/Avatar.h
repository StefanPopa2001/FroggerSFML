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
        RectangleShape shapeAvatar;
        Texture textureAvatar;
        ContextMovingState* movingstate = new ContextMovingState;

    public:
        void die();
        void win();
        Avatar();
        virtual ~Avatar();
        RectangleShape getGraphicEntity();
        void putAvatarStartPosition();
        void moveAvatar(Event e);
        void replay();

};

#endif // JOUEUR_H
