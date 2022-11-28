#ifndef MENUJEU_H
#define MENUJEU_H
#include <SFML/Graphics.hpp>

class MenuJeu
{
    public:
        MenuJeu(float width, float height);
        virtual ~MenuJeu();

        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() {return selectedItemIndex;}

    protected:

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text titreJeu;
        sf::Text boutons[3];
};

#endif // MENUJEU_H
