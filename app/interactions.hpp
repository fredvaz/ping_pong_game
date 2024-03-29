#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"

// Find whether two entities overlap
bool isInteracting(const Entity &e1, const Entity &e2);

// Resolve potential collision between the ball and the paddle
void handleCollision(Ball &b, const Paddle &p);

// Resolve potential collision between the ball and a brick
void handleCollision(Ball &b, Brick &p);

#endif // INTERACTIONS_H
