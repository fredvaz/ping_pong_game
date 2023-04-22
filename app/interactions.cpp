
#include "interactions.hpp"

// Find whether two entities overlap
bool isInteracting(const Entity &e1, const Entity &e2)
{
    auto box1 = e1.getBoundingBox();
    auto box2 = e2.getBoundingBox();

    return box1.intersects(box2);
}

// Resolve potential collision between the ball and the paddle
void handleCollision(Ball &b, const Paddle &p)
{
    if (isInteracting(p, b))
    {
        // Make the ball bounce upwards
        b.moveUp();

        // Make the new direction depend on where the collision occurs on the paddle
        // If the collision is on the left of the paddle, make the ball bounce to the left
        if (b.x() < p.x())
            b.moveLeft();
        else
            b.moveRight();
    }
}


// Resolve potential collision between the ball and a brick
void handleCollision(Ball &ball, Brick &brick)
{

    if (isInteracting(brick, ball))
    {
        // The brick is destroyed
        brick.destroy();

        // First we find the amount of overlap in each direction
        float left_overlap = ball.right() - brick.left();
        float right_overlap = brick.right() - ball.left();
        float top_overlap = ball.bottom() - brick.top();
        float bottom_overlap = brick.bottom() - ball.top();

        // If the left overloa is smaller than the right overlap, the ball hit the left side
        bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
        bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

        // Use the right or left overlap as appropriate
        float min_x_overlap = from_left ? left_overlap : right_overlap;
        float min_y_overlap = from_top ? top_overlap : bottom_overlap;

        // If the ball hit the left or right side of the brick, change its horizontal direction
        // If the ball hit the top or bottom of the brick, change its vertical direction
        if (std::abs(min_x_overlap) < std::abs(min_y_overlap))
        {
            if (from_left)
                ball.moveLeft();
            else
                ball.moveRight();
        }    
        else
        {
            if (from_top)
                ball.moveUp();
            else
                ball.moveDown();
        }


    }
    

}