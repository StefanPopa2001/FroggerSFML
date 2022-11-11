#include "View/Rendu.h"
#include "View/Plateau.h"
#include "Model/Joueur.h"
#include "Model/Voiture.h"
#include <iostream>

Rendu::Rendu()
{
    joueur = new Joueur;

    //placement voiture vecteur
    for (int i=0; i<12;i++)
    {
        voitures.push_back(new Voiture);
    }
    int i=0;
    for(Voiture* v: voitures)
    {
        if (i%2==0)
        {
            v->getObstacle().getEntiteGraphique().setPosition(-100.f, Rendu::compteurPosY);
            v->getObstacle().setRight(false);
        }
        else
        {
            v->getObstacle().getEntiteGraphique().setPosition(700.f, Rendu::compteurPosY);
            v->getObstacle().getEntiteGraphique().scale(-1,1);
            v->getObstacle().setRight(true);
        }


        Rendu::compteurPosY +=50;

        if (Rendu::compteurPosY==350 || Rendu::compteurPosY==650)
        {
            Rendu::compteurPosY+=50;
        }
        i++;
    }
}

Rendu::~Rendu()
{

    delete joueur;
}

int Rendu::afficherJeu()
{
    // Create the main window
    const unsigned WINDOW_WIDTH = 700;
    const unsigned WINDOW_HEIGHT = 900;

    sf::RenderWindow app(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Frogger");

    app.setVerticalSyncEnabled(true);
    app.setFramerateLimit(60);

    joueur->getAvatar()->mettreAvatarPositionDepart();
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
                joueur->getAvatar()->deplacerAvatar(event);
            }
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(plateau.getEntiteGraphique());

//        app.draw(v.getObstacle().getEntiteGraphique());
//        app.draw(v1.getObstacle().getEntiteGraphique());



        app.draw(joueur->getAvatar()->getEntiteGraphique());

        int i =0;
        for(Voiture* v: voitures)
        {

            FloatRect VoitureBounds = v->getObstacle().getEntiteGraphique().getGlobalBounds();
            FloatRect JoueurBounds = joueur->getAvatar()->getEntiteGraphique().getGlobalBounds();

            if(JoueurBounds.intersects(VoitureBounds))
            {
                joueur->getAvatar()->mettreAvatarPositionDepart();
                //vies--;
                //std::cout<<std::to_string(vies)<<std::endl;
                //window.clear();

            }

            app.draw(v->getObstacle().getEntiteGraphique());
            if (!(v->getObstacle().isRight()))
            {
                v->deplacer(1);
                if (v->getObstacle().getEntiteGraphique().getPosition().x > WINDOW_WIDTH+100)
                {
                    int random = rand()%2;
                    if (random==0)
                    {
                        v->getObstacle().getEntiteGraphique().move(-800,0);
                    }
                    else
                    {
                        v->getObstacle().setRight(true);
                        v->getObstacle().getEntiteGraphique().scale(-1,1);
                    }
                }
            }
            else
            {
                v->deplacer(-1);
                if (v->getObstacle().getEntiteGraphique().getPosition().x < -100)
                {
                    int random = rand()%2;
                    if (random==0)
                    {
                        v->getObstacle().setRight(false);
                        v->getObstacle().getEntiteGraphique().scale(-1,1);
                    }
                    else
                    {
                        v->getObstacle().getEntiteGraphique().move(800,0);
                        v->getObstacle().getEntiteGraphique().scale(1,1);
                    }
                }
            }
            i++;
        }
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}


