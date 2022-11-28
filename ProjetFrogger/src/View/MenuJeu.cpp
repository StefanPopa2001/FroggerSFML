#include "MenuJeu.h"
#include <SFML/Graphics.hpp>
using namespace sf;

MenuJeu::MenuJeu(float width, float height)
{
    if(!font.loadFromFile("Ressources/BubbleLemonDemoOutline.ttf"))
    {

    }
    titreJeu.setFont(font);

    titreJeu.setFillColor(Color::Green);
    titreJeu.setString("Frogger");
    titreJeu.setCharacterSize(80);
    titreJeu.setPosition(sf::Vector2f(width / 2 - 200, height / (20+1) * 1 ));

    boutons[0].setFont(font);
    boutons[0].setFillColor(sf::Color::White);
    boutons[0].setString("Jouer");
    boutons[0].setPosition(sf::Vector2f(width / 2 - 70, height / (4+1) * 2));


    boutons[1].setFont(font);
    boutons[1].setFillColor(sf::Color::White);
    boutons[1].setString("Options");
    boutons[1].setPosition(sf::Vector2f(width / 2 - 70, height / (4+1) * 3));

    boutons[2].setFont(font);
    boutons[2].setFillColor(sf::Color::White);
    boutons[2].setString("Quitter");
    boutons[2].setPosition(sf::Vector2f(width / 2 - 70, height / (4+1) * 4));

    selectedItemIndex = 0;
}

MenuJeu::~MenuJeu()
{
    //dtor
}


void MenuJeu::draw(sf::RenderWindow &window)
{

    window.draw(titreJeu);

    for(int i=0;i<3;i++)
    {
       window.draw(boutons[i]);
    }

}

void MenuJeu::MoveUp(){

if(selectedItemIndex - 1 >= 0){
    boutons[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex--;
    boutons[selectedItemIndex].setFillColor(sf::Color::Green);


}

}

void MenuJeu::MoveDown(){

if(selectedItemIndex + 1 < 3){
    boutons[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex++;
    boutons[selectedItemIndex].setFillColor(sf::Color::Green);

}

}

