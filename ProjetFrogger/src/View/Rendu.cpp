#include "View/Rendu.h"
#include "View/Plateau.h"
#include "Model/Joueur.h"
#include "Model/Voiture.h"

Rendu::Rendu()
{
}

Rendu::~Rendu()
{
    //dtor
}

int Rendu::afficherJeu()
{


    //Création des éléments du jeu
    Joueur j;
    Plateau p;
    Voiture v;
    j.getAvatar()->mettreAvatarPositionDepart();

    // Create the main window
    const unsigned WINDOW_WIDTH = 700;
    const unsigned WINDOW_HEIGHT = 900;

    sf::RenderWindow app(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Frogger");

    app.setVerticalSyncEnabled(true);
    app.setFramerateLimit(60);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                app.close();
            }

            else if (event.type == sf::Event::KeyPressed)
            {
                j.getAvatar()->deplacerAvatar(event);
            }
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(p.getEntiteGraphique());

        app.draw(v.getObstacle().getEntiteGraphique());
        v.deplacer(1);

        app.draw(j.getAvatar()->getEntiteGraphique());

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
