#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Obstacle
{
    private:
        RectangleShape shapeObstacle;
        Texture textureObstacle;
        bool right;

    public:
        Obstacle(int type);
        virtual ~Obstacle();
        RectangleShape& getGraphicEntity();
        void setRight(bool b);
        bool isRight();



};

#endif // JOUEUR_H
