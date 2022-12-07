#include "GameMenu.h"
#include <SFML/Graphics.hpp>
using namespace sf;

GameMenu::GameMenu(float width, float height)
{
    if(!font.loadFromFile("Ressources/BubbleLemonDemoOutline.ttf"))
    {

    }

    shapeMenu = RectangleShape({700,900}),
    textureMenu.loadFromFile("Ressources/menu.png");
    shapeMenu.setTexture(&textureMenu);
    shapeMenu.setPosition(0.f, 0.f);

    //entité graphique du menu principal
    titreJeu.setFont(font);
    titreJeu.setFillColor(Color::Green);
    titreJeu.setString("Frogger");
    titreJeu.setCharacterSize(80);
    titreJeu.setPosition(sf::Vector2f(width / 2 - 200, height / (20+1) * 1 ));

    boutons[0].setFont(font);
    boutons[0].setFillColor(sf::Color::White);
    boutons[0].setString("Play");
    boutons[0].setPosition(sf::Vector2f(width / 2 - 70, height / (4+1) * 2));

    boutons[1].setFont(font);
    boutons[1].setFillColor(sf::Color::White);
    boutons[1].setString("Options");
    boutons[1].setPosition(sf::Vector2f(width / 2 - 70, height / (4+1) * 3));

    boutons[2].setFont(font);
    boutons[2].setFillColor(sf::Color::White);
    boutons[2].setString("Quit");
    boutons[2].setPosition(sf::Vector2f(width / 2 - 70, height / (4+1) * 4));

    selectedItemIndex = 0;
}

GameMenu::~GameMenu()
{
    //dtor
}


void GameMenu::draw(sf::RenderWindow &window)
{

window.draw(shapeMenu);
//dessine le menu
    window.draw(titreJeu);

    for(int i=0;i<3;i++)
    {
       window.draw(boutons[i]);
    }

}

//permet de se deplacer dans le menu
void GameMenu::MoveUp(){

if(selectedItemIndex - 1 >= 0){
    boutons[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex--;
    boutons[selectedItemIndex].setFillColor(sf::Color::Green);
}

}

void GameMenu::MoveDown(){

if(selectedItemIndex + 1 < 3){
    boutons[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex++;
    boutons[selectedItemIndex].setFillColor(sf::Color::Green);

}

}

