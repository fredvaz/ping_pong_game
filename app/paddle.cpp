#include "paddle.hpp"

//

sf::Texture Paddle::texture;

Paddle::Paddle(float x, float y) : MovingEntity()
{
    texture.loadFromFile("paddle.png");
    sprite.setTexture(texture);

    // Set the intitial postion and velocity of the paddle
    sprite.setPosition(x, y);
 
    // Set the velocity of the paddle, the paddle can only move sideways
    velocity = {constants::paddle_speed, 0.0f};

    // Make the operations relative to the sprite's centre
    sprite.setOrigin(getCentre());
}

// Compute the paddle's new position
void Paddle::update()
{
    process_player_input();
    sprite.move(velocity);
}
void Paddle::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

// Process the input from the player
void Paddle::process_player_input()
{
    // Left arrow key pressed - move to the left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (x() > 0)
            velocity.x = -constants::paddle_speed;
        else
            velocity.x = 0;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (x() <= constants::window_width)
            velocity.x = constants::paddle_speed;
        else
            velocity.x = 0;
    }
    else{
        velocity.x = 0;
    }
}

void Paddle::moveUp() noexcept
{
    // Not possible move up
}

void Paddle::moveDown() noexcept
{
    // Not possible move up
}

void Paddle::moveLeft() noexcept
{
    velocity.x = -constants::ball_speed;
}

void Paddle::moveRight() noexcept
{
    velocity.x = constants::ball_speed;
}