#include <SFML/Graphics.hpp>
#include <Model/Player.h>
#include <View/GameBoard.h>
#include <View/Render.h>
#include <iostream>
#include <View/GameMenu.h>

using namespace std;


int main()
{
     sf::RenderWindow app(sf::VideoMode(700, 900), "Frogger");


    GameMenu menu(app.getSize().x,app.getSize().y);

    Render r;

    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            switch(event.type)
            {
           case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:


                    switch(menu.GetPressedItem())
                    {
                    case 0:
                        std::cout<<"Play button pressed"<< std::endl;
                        app.close();

                        r.showGame();
                        break;
                    case 1:
                        std::cout<<"Option button pressed"<< std::endl;

                        break;
                    case 2:
                        app.close();
                        break;
                    }
                    break;
                 default:
                     break;
                }
                break;

            case sf::Event::Closed:
                app.close();
                break;
            default:
                break;
            }
            break;

        }

        app.clear();

        menu.draw(app);

        app.display();
    }

    return 69;

}

