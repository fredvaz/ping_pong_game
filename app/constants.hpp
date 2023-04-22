#ifndef CONSTANTS_H
#define CONSTANTS_H

//

struct constants
{
    static constexpr int window_width{800};
    static constexpr int window_height{600};
    static constexpr float ball_speed{6.0f};
    static constexpr float paddle_width{60.0f};
    static constexpr float paddle_height{20.0f};
    static constexpr float paddle_speed{8.0f};
    static constexpr float brick_width{43.0f};
    static constexpr float brick_height{20.0f};
    static constexpr float brick_offset{brick_width/2.0f};
    static constexpr int brick_columns{10};
    static constexpr int brick_rows{4};
};

#endif // CONSTANTS_H
