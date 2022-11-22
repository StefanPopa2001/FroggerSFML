#ifndef PLATEAU_H
#define PLATEAU_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Plateau
{
    private:
        RectangleShape formePlateau;
        Texture texturePlateau;

        RectangleShape loseForm;
        Texture textureLose;


        bool loose;

    public:
        Plateau();
        virtual ~Plateau();
        RectangleShape getEntiteGraphique();
        void setLose(bool lose);
        bool isLoose();



};

#endif // JOUEUR_H
