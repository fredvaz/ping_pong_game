
#include "brick.hpp"

// Initialize static data
sf::Texture Brick::texture;

Brick::Brick(float x, float y) : Entity()
{
    // Load the texture
    texture.loadFromFile("brick01.png");
    sprite.setTexture(texture);

    // Set the position of the brick
    sprite.setPosition(x, y);

    // Make the brick operations relative to sprite's centre
    sprite.setOrigin(getCentre());

}

// Compare the brick's new position
void Brick::update()
{
    // Nothing to do here
}

// Ask th window to draw the sprite for us
void Brick::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}