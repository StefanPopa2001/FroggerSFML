#include "View/Render.h"
#include "View/GameBoard.h"
#include "Model/Player.h"
#include "Model/Car.h"
#include "View/Life.h"

#include <iostream>

Render::Render()
{

    //creation du joueur
    player = new Player;
    player->getAvatar()->putAvatarStartPosition();

    if (!font.loadFromFile("Ressources/font/arial.ttf"))
    {
        std::cout <<"ca marche pas"<<std::endl;

    }

    score.setString("");
    score.setFont(font);
    score.setCharacterSize(100);
    score.setFillColor(Color::Black);
    score.setPosition(450.f, -20.f);

    level.setString("");
    level.setFont(font);
    level.setCharacterSize(50);
    level.setFillColor(Color::Black);
    level.setPosition(70.f, 40.f);

    gameEnd.setString("");
    gameEnd.setFont(font);
    gameEnd.setCharacterSize(20);
    gameEnd.setFillColor(Color::Black);
    gameEnd.setPosition(0.f, 450.f);

    //placement des vies dans le vecteur en fonction du nombre de vie du joueur
    for (int i=0;i<player->getLife();i++)
    {
        lifes.push_back(new Life);
    }
    //placement graphique des vies
    for (Life* life:lifes)
    {
        life->getShape().setPosition(Life::firstX,0.f);

        Life::firstX +=50;
    }

    //placement des bieres dans le vecteur
    for (int i=0;i< 2;i++)
    {
        beers.push_back(new Beer);
    }

    //placement biere graphique
    for (Beer* beer:beers)
    {
        beer->getShape().setPosition(0,0);
        beer->getShape().setPosition((rand()%14)*50,150+((rand())%12)*50);
    }

    //placement voiture vecteur
    for (int i=0; i<12;i++)
    {
        cars.push_back(new Car);
    }
    //le %2 permet de changer la direction d'une voiture sur 2
    int i=0;
    for(Car* v: cars)
    {
        if (i%2==0)
        {
            v->getObstacle().getGraphicEntity().setPosition(-100.f, Render::compteurPosY);
            v->getObstacle().setRight(false);
        }
        else
        {
            v->getObstacle().getGraphicEntity().setPosition(700.f, Render::compteurPosY);
            v->getObstacle().getGraphicEntity().scale(-1,1);
            v->getObstacle().setRight(true);
        }
        Render::compteurPosY +=50;
        if (Render::compteurPosY==350 || Render::compteurPosY==650)
        {
            Render::compteurPosY+=50;
        }
        i++;
    }
}

Render::~Render()
{

    for(Car* v: cars){
        delete v;
    }
    cars.clear();

    for(Life* l: lifes){
        delete l;
    }
    for(Beer* b: beers){
        delete b;
    }
    beers.clear();

    delete player;
}

int Render::showGame()
{
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
                player->getAvatar()->moveAvatar(event);
            }
        }
        // Clear screen

        app.clear();
        if(!board.isWin() && !board.isLoose()){
            score.setString(std::to_string(player->getNbPoints()));
            level.setString(std::to_string(player->getLevel()));
        }
        else{
            score.setString("");
            level.setString("");
            sf::RenderWindow renderwindow(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Replay");
            menuEndGame menuendGame(renderwindow.getSize().x,renderwindow.getSize().y);
            app.clear();

            while(renderwindow.isOpen())
            {

             int nbr;
             if(board.isWin())
                    nbr=1;
                else
                    nbr=2;
                        // Process events
        sf::Event event;
        while (renderwindow.pollEvent(event))
        {
            switch(event.type)
            {
           case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    menuendGame.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menuendGame.MoveDown();
                    break;

                case sf::Keyboard::Return:


                    switch(menuendGame.GetPressedItem())
                    {
                    case 0:
                        std::cout<<"Play button pressed"<< std::endl;



                        renderwindow.close();
                        player->setLevel(1);
                        player->setLife(3);
                        lifes.clear();
                        player->setNbPoints(0);
                        board.setLose(false);
                        board.setWin(false);
                        player->getAvatar()->replay();
                        for (int i=0;i<player->getLife();i++)
                        {
                            lifes.push_back(new Life);
                        }
                        Life::firstX=150;
                        //placement graphique des vies
                        for (Life* life:lifes)
                        {
                            life->getShape().setPosition(Life::firstX,0.f);

                            Life::firstX +=50;
                        }
                        app.clear();
                        //r.showGame();
                        break;
                    case 1:
                        std::cout<<"Option button pressed"<< std::endl;
                        app.close();
                        renderwindow.close();
                        break;
                    }
                    break;
                 default:
                     break;
                }
                break;

            case sf::Event::Closed:
                renderwindow.close();
                app.close();
                break;
            default:
                break;
            }
            break;

                    }
                    renderwindow.clear();
                    renderwindow.draw(board.getGraphicEntityReplay(nbr));
                    renderwindow.draw(gameEnd);
                    menuendGame.draw(renderwindow);
                    renderwindow.display();
            }




        }
        // Draw the sprite
        app.draw(board.getGraphicEntity());
        app.draw(score);
        app.draw(level);

        if (board.isLoose() || board.isWin())
        {
            score.setString("ement");
            level.setString("change");
            app.draw(gameEnd);
        }

        for (Life* life:lifes)
        {
            app.draw(life->getShape());
        }

        for (Beer* beer:beers)
        {
            app.draw(beer->getShape());
        }

        app.draw(player->getAvatar()->getGraphicEntity());

        int i =0;

         if (player->getLevel() == 2)
            {
                board.setWin(true);

                level.setString("");
                player->getAvatar()->win();
                gameEnd.setString("You completed "+std::to_string(Player::level) +" levels and collected "+std::to_string(player->getNbPoints())+" beers");
            }



        //permet de verifier si il y a collision entre le joueur et n'importe qu'elle voiture du jeu
        //si il y a collision on decremente la vie
        for(Car* v: cars)
        {
            FloatRect VoitureBounds = v->getObstacle().getGraphicEntity().getGlobalBounds();
            FloatRect JoueurBounds = player->getAvatar()->getGraphicEntity().getGlobalBounds();

            if(JoueurBounds.intersects(VoitureBounds))
            {
                player->getAvatar()->putAvatarStartPosition();
                player->looseLife();
                lifes.pop_back();
                if (player->getLife() == 0)
                {
                    board.setLose(true);


                    player->getAvatar()->die();
                    gameEnd.setString("You completed "+std::to_string(Player::level) +" levels and collected "+std::to_string(player->getNbPoints())+" beers");
                }
            }
            //on regarde si la voiture a commencé a droite ou a gauche de l'ecran,
            //ensuite on genere un random entre 0 et 1 pour savoir si elle va repartir a gauche ou a droite
            app.draw(v->getObstacle().getGraphicEntity());
            if (!(v->getObstacle().isRight()))
            {
                v->moove(1);
                if (v->getObstacle().getGraphicEntity().getPosition().x > WINDOW_WIDTH+100)
                {
                    int random = rand()%2;
                    if (random==0)
                    {
                        v->getObstacle().getGraphicEntity().move(-800,0);
                    }
                    else
                    {
                        v->getObstacle().setRight(true);
                        v->getObstacle().getGraphicEntity().scale(-1,1);
                    }
                }
            }
            else
            {
                v->moove(-1);
                if (v->getObstacle().getGraphicEntity().getPosition().x < -100)
                {
                    int random = rand()%2;
                    if (random==0)
                    {
                        v->getObstacle().setRight(false);
                        v->getObstacle().getGraphicEntity().scale(-1,1);
                    }
                    else
                    {
                        v->getObstacle().getGraphicEntity().move(800,0);
                        v->getObstacle().getGraphicEntity().scale(1,1);
                    }
                }
            }
            i++;
        }

        //verifie si le joueur attrape une biere et la deplace + augmente nbpoints du joueur
        for (Beer* beer:beers)
        {
            FloatRect beerbounds = beer->getShape().getGlobalBounds();
            FloatRect playerBounds = player->getAvatar()->getGraphicEntity().getGlobalBounds();

            if(playerBounds.intersects(beerbounds))
            {
                player->winPoint();
                beer->getShape().setPosition(1000,1000);
                beer->getShape().setPosition((rand()%14)*50,150+((rand())%12)*50);
            }
        }
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}


