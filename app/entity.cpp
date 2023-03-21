#include "entity.hpp"

//

// Get the bounding box of a sprite
sf::FloatRect Entity::getBoundingBox() const noexcept
{
    return sprite.getGlobalBounds();
}

// Get the centre of a sprite
sf::Vector2f Entity::getCentre() const noexcept
{
    auto box = getBoundingBox();
    return {box.width / 2.0f, box.height / 2.0f};
}

// Get the position of the sprite
float Entity::x() const noexcept
{
    return sprite.getPosition().x;
}
float Entity::y() const noexcept
{
    return sprite.getPosition().y;
}
