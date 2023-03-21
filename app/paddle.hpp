#ifndef PADDLE_H
#define PADDLE_H

//

#include "constants.hpp"
#include "entity.hpp"

class Paddle : public MovingEntity
{

public:
    Paddle(float x, float y);

    // Declaration of the pure virtual functions from Entity to be implemented in this Class
    void update() override;
    void draw(sf::RenderWindow &window) override;

private:
    static sf::Texture texture;
};

#endif // PADDLE_H
