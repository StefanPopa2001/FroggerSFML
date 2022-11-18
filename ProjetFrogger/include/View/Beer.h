#ifndef BEER_
#define BEER_
#include <SFML/Graphics.hpp>

using namespace sf;

class Beer
{
    private:
        RectangleShape lifeForm;
        Texture lifeTexture;
    public:
        Beer();
        virtual ~Beer();
        Beer(const Beer& other);
        Beer& operator=(const Beer& other);

        RectangleShape& getShape();

    protected:
};

#endif // BEER_
