#ifndef BRICK_H
#define BRICK_H

#include "constants.hpp"
#include "entity.hpp"

// Class to represt a brick and Inherits from Entity
// A grid of brick is displayed across the top of the screen
// This grid will be represented by am std::vector of brick objects
// When the ball hits a brick, the brick is destroyed and disappears
// When a brick is destroyed, it is deleteded from the vector
class Brick : public Entity
{

public:
    // Constructors
    Brick(float x, float y);

    // Implement the pure virtual functions
    void update() override;
    void draw(sf::RenderWindow &window) override;

private: 
    static sf::Texture texture;

};

#endif // BRICK_H