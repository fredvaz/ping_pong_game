#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

//

// Abstract Class to represent any graphical entity on the screen
class Entity
{

public:
    // Virtual Destructor
    virtual ~Entity() {}

    // Pure virtual functions: the graphical entities must implement these functions

    // update() member function shall compute the new position, appearance of the object
    virtual void update() = 0;

    // draw() member function shall cause the updated object to be displayed in the game window
    virtual void draw(sf::RenderWindow &window) = 0;

    // Get the bounding box of a sprite
    sf::FloatRect getBoundingBox() const noexcept;

    // Get the centre of a sprite
    sf::Vector2f getCentre() const noexcept;

    // Get the position of the sprite
    float x() const noexcept;
    float y() const noexcept;

protected:
    sf::Sprite sprite;
};

// Abstract Class to represent graphical entities which can move around the screen
class MovingEntity : public Entity
{

public:
    // Helper functions inherited from parent class
    // float x();
    // float y();

    // Pure virtual functions inherited from parent class
    // virtual void update() = 0;
    // virtual void draw(sf::RenderWindow& window) = 0;
    // etc

protected:
    // SFML vector to store the object's velocity
    // This is the distance the ball moves between screen updates
    sf::Vector2f velocity;
};

#endif // ENTITY_H
