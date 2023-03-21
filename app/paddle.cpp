#include "paddle.hpp"

//

sf::Texture Paddle::texture;

Paddle::Paddle(float x, float y) : MovingEntity()
{
    texture.loadFromFile("paddle.png");
    sprite.setTexture(texture);

    // Set the intitial postion and velocity of the paddle
    sprite.setPosition(x, y);
    velocity = {0.0f, 0.0f};
}

// Compute the paddle's new position
void Paddle::update()
{
    sprite.move(velocity);
}
void Paddle::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
