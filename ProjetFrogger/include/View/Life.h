#ifndef LIFE_H
#define LIFE_H
#include <SFML/Graphics.hpp>

using namespace sf;
class Life
{
    private:
        RectangleShape lifeForm;
        Texture lifeTexture;
    public:
        Life();
        virtual ~Life();
        Life(const Life& other);
        Life& operator=(const Life& other);

        RectangleShape& getShape();

        inline static int firstX = 150;

    protected:
};

#endif // LIFE_H
