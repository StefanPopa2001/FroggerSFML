#ifndef MENUENDGAME_H
#define MENUENDGAME_H
#include "View/Rendu.h"
#include <SFML/Graphics.hpp>

class menuEndGame
{

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text buttons[2];


    public:
        menuEndGame(float width, float height);
        virtual ~menuEndGame();
        menuEndGame(const menuEndGame& other);
        menuEndGame& operator=(const menuEndGame& other);
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() {return selectedItemIndex;}

};

#endif // MENUENDGAME_H
