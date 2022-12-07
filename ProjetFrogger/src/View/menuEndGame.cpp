#include "menuEndGame.h"

menuEndGame::menuEndGame(float width, float height)
{
    if(!font.loadFromFile("Ressources/BubbleLemonDemoOutline.ttf"))
    {

    }
    buttons[0].setFont(font);
    buttons[0].setFillColor(sf::Color::White);
    buttons[0].setString("Replay");
    buttons[0].setPosition(sf::Vector2f(width / 2 - 70, height / (4+1) * 2));


    buttons[1].setFont(font);
    buttons[1].setFillColor(sf::Color::White);
    buttons[1].setString("Exit");
    buttons[1].setPosition(sf::Vector2f(width / 2 - 70, height / (4+1) * 3));


    selectedItemIndex = 0;
}

menuEndGame::~menuEndGame()
{
    //dtor
}

menuEndGame::menuEndGame(const menuEndGame& other)
{
    //copy ctor
}

menuEndGame& menuEndGame::operator=(const menuEndGame& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void menuEndGame::draw(sf::RenderWindow &window)
{

    for(int i=0;i<2;i++)
    {
       window.draw(buttons[i]);
    }

}

void menuEndGame::MoveUp(){

if(selectedItemIndex - 1 >= 0){
    buttons[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex--;
    buttons[selectedItemIndex].setFillColor(sf::Color::Green);
}

}

void menuEndGame::MoveDown(){

if(selectedItemIndex + 1 < 2){
    buttons[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex++;
    buttons[selectedItemIndex].setFillColor(sf::Color::Green);

}
}
