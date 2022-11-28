#include <SFML/Graphics.hpp>
#include <Model/Joueur.h>
#include <View/Plateau.h>
#include <View/Rendu.h>
#include <iostream>
#include <View/MenuJeu.h>

using namespace std;


int main()
{
     sf::RenderWindow app(sf::VideoMode(800, 600), "Frogger");


    MenuJeu menu(app.getSize().x,app.getSize().y);

    Rendu r;

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

                   // sf::RenderWindow play(sf::VideoMode(800,600),"Frogger");


                    switch(menu.GetPressedItem())
                    {
                    case 0:
                        std::cout<<"Play button pressed"<< std::endl;
                        app.close();

                        r.afficherJeu();

                      /*  while(play.isOpen())
                        {
                            sf::Event aevent;
                          //  play.draw();
                            while(play.pollEvent(aevent))
                            {
                                if(aevent.type == sf::Event::Closed)
                                {
                                    play.close();
                                }
                            }
                            options.close();
                            play.clear();
                            //play.draw()
                            play.display();
                        }*/

                        break;
                    case 1:
                        std::cout<<"Option button pressed"<< std::endl;

                        break;
                    case 2:
                        app.close();
                        break;
                    }
                }
                break;

            case sf::Event::Closed:
                app.close();
                break;


            }


        }

        // Clear screen
        app.clear();

        menu.draw(app);

        // Draw the sprite
        //app.draw(sprite);



        // Update the window
        app.display();
    }


    //r.afficherJeu();




    return 69;

}

