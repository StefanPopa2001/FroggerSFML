#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Obstacle
{
    private:
        RectangleShape formeObstacle;
        Texture textureObstacle;

    public:
        Obstacle(int type);
        virtual ~Obstacle();
        RectangleShape& getEntiteGraphique();

};

#endif // JOUEUR_H
