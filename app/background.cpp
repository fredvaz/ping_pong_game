#include "background.hpp"

//

Background::Background(float x, float y) : Entity()
{

    rectangle.setSize({constants::window_width, constants::window_height});
    rectangle.setFillColor(sf::Color::Cyan);

    // Set the intitial postion of the background
    rectangle.setPosition(x, y);
}

// Compute the background new postion
void Background::update()
{
    // Does not update
}
void Background::draw(sf::RenderWindow &window)
{
    window.draw(rectangle);
}
