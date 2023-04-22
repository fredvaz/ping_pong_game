#ifndef BALL_H
#define BALL_H

#include "constants.hpp"
#include "entity.hpp"

//

// Class to represent the boucing ball
class Ball : public MovingEntity
{

public:
    Ball(float x, float y);

    // Declaration of the pure virtual functions from Entity to be implemented in this Class
    void update() override;
    void draw(sf::RenderWindow &window) override;

    // Implement the helper functions
    void moveUp() noexcept override;
    void moveDown() noexcept override;
    void moveLeft() noexcept override;
    void moveRight() noexcept override;

private:
    static sf::Texture texture;
    sf::CircleShape circle;
};

#endif // BALL_H
