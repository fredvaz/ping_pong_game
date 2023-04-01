#include "ball.hpp"

//

// Initialize static data
sf::Texture Ball::texture;

Ball::Ball(float x, float y) : MovingEntity()
{

    texture.loadFromFile("ball.png");
    sprite.setTexture(texture);
    // circle.setRadius(10.0f);
    // circle.setFillColor(sf::Color::Red);

    // Set the intitial postion and velocity of the ball
    sprite.setPosition(x, y);
    // circle.setPosition(x, y);
    velocity = {constants::ball_speed, constants::ball_speed};

    // By default operations are relative to sprite's top left corner
    // Make them relative to the sprite's centre
    sprite.setOrigin(getCentre());
}

// Compute the ball new postion
void Ball::update()
{
    // Move the position of the ball
    sprite.move(velocity);
    // circle.move(velocity);

    if (x() < 0)
        velocity.x = -velocity.x;

    if (x() > constants::window_width)
        velocity.x = -velocity.x;

    if (y() < 0)
        velocity.y = -velocity.y;

    if (y() > constants::window_height)
        velocity.y = -velocity.y;
}
void Ball::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    // window.draw(circle);
}

void Ball::moveUp() noexcept
{
    velocity.y = -constants::ball_speed;
}

void Ball::moveLeft() noexcept
{
    velocity.x = -constants::ball_speed;
}

void Ball::moveRight() noexcept
{
    velocity.x = constants::ball_speed;
}
