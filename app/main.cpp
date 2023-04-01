/*

Ping Pong Game

General Notes:
    Code for a "breakout" game based on a talk by Vittorio Romeo
    Uses the SFML graphics library

   [REF]:

*/
#include <SFML/Graphics.hpp>
#include <string>
#include <random>
#include "constants.hpp"
#include "background.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "interactions.hpp"

//

using namespace std;
using namespace std::literals;

//

class Player
{

public:
    // Constructor: arguments are the initial coordinates of the player centre
    // SFML used the computer graphics convention: (0, 0) is the top left of the screen
    Player(float x, float y)
    {
        // Set the intial position and velocity
        velocity = {v_x, v_y};
        circle.setPosition(x, y);

        // Set the graphical properties
        circle.setRadius(5.0f);
        circle.setFillColor(sf::Color::Red);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(circle);
    }

    // Computes the player new position
    void update()
    {
        // Change the direction of movement at random
        v_x = bd(mt) ? v_x : -v_x;
        v_y = bd(mt) ? v_y : -v_y;

        // Move the player to its new position
        circle.move({v_x, v_y});
    }

private:
    // Static random number engine and Bernoulli distrivution objects from random Library
    static mt19937 mt;
    static bernoulli_distribution bd;

    // Player properties, SML uses float internally
    float v_x{4.0f};
    float v_y{4.0f};
    sf::Vector2f velocity;
    sf::CircleShape circle;
};

// Initialization of the Objects
mt19937 Player::mt;
bernoulli_distribution Player::bd;

//

int main()
{

    // Creates the Background object
    Background background(0.0f, 0.0f);

    // Creates a Player object in the middle of the screen
    // Player player(constants::window_width / 2.0, constants::window_height / 2.0);
    Ball ball(constants::window_width / 2.0, constants::window_height / 2.0);

    // Create a paddle object at the bottom of the screen in the middle
    Paddle paddle(constants::window_width / 2.0f, constants::window_height - constants::paddle_height);

    // Creates the game window using an object of class RenderWindow
    // The constructor takes an SFML 2D vector with the window dimensions and an std::string with the window title
    sf::RenderWindow game_window({constants::window_width, constants::window_height}, "Ping Pong Game v1");

    // Limit the framerate
    game_window.setFramerateLimit(60);

    // Game loop:
    // Clear the Screen -> Check for new events -> Calculate the updated graphics
    // -> Display the updated graphics
    while (game_window.isOpen())
    {

        game_window.clear(sf::Color::Magenta);

        sf::Event event;

        // if the user clicked on "Close" we close the window, and the games ends
        while (game_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                game_window.close();
                break;
            }
        }
        // OR pressed "Escape"
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            game_window.close();
            break;
        }

        // Calculate the updated graphics
        background.update();
        ball.update();
        paddle.update();
        handleCollision(ball, paddle);

        // Display the updated graphics
        background.draw(game_window);
        ball.draw(game_window);
        paddle.draw(game_window);
        game_window.display();
    }

    return 0;
}
