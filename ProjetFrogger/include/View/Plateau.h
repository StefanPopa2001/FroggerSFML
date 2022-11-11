#ifndef PLATEAU_H
#define PLATEAU_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Plateau
{
    private:
        RectangleShape formePlateau;
        Texture texturePlateau;

    public:
        Plateau();
        virtual ~Plateau();
        RectangleShape getEntiteGraphique();


};

#endif // JOUEUR_H
