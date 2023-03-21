#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "constants.hpp"
#include "entity.hpp"

//

// Class to represent the background of the game window
class Background : public Entity
{

public:
    // Constructor: arguments are the initial coordinates of the player centre
    // SFML used the computer graphics convention: (0, 0) is the top left of the screen
    Background(float x, float y);

    // Declaration of the pure virtual functions from Entity to be implemented in this Class
    void update() override;
    void draw(sf::RenderWindow &window) override;

private:
    sf::RectangleShape rectangle;
};

#endif // BACKGROUND_H
