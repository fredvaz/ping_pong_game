
#include "interactions.hpp"

// Find whether two entities overlap
bool isInteracting(const Entity &e1, const Entity &e2)
{
    auto box1 = e1.getBoundingBox();
    auto box2 = e2.getBoundingBox();

    return box1.intersects(box2);
}

// Resolve potential collision between the ball and the paddle
void handleCollision(Ball & b, const Paddle &p)
{
    if (isInteracting(p, b))
    {
        // Make the ball bounce upwards
        b.moveUp();

        // Make the new direction depend on where the collision occurs on the paddle
        // If the collision is on the left of the paddle, make the ball bounce to the left
        if ( b.x() < p.x())
            b.moveLeft();
        else
            b.moveRight();
    }
}
