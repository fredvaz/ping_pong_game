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

    // Implement the helper functions
    void moveUp() noexcept override;
    void moveLeft() noexcept override;
    void moveRight() noexcept override;

private:
    static sf::Texture texture;
    // Process the input from the player
    void process_player_input();
};

#endif // PADDLE_H
