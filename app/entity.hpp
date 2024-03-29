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

    // Helper functions to get the edges of the sprite
    float left() const noexcept;
    float right() const noexcept;
    float top() const noexcept;
    float bottom() const noexcept;

    // Helper functions for the state of the entity
    void destroy() noexcept;
    bool isDestroyed() const noexcept;

protected:
    sf::Sprite sprite;
    // Boolean member  tracks the entity's on the screen
    bool destroyed{false};
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

    // Helper Functions to change the sprite's direction
    virtual void moveUp() noexcept = 0;
    virtual void moveDown() noexcept = 0;
    virtual void moveLeft() noexcept = 0;
    virtual void moveRight() noexcept = 0;

protected:
    // SFML vector to store the object's velocity
    // This is the distance the ball moves between screen updates
    sf::Vector2f velocity;
};

#endif // ENTITY_H
