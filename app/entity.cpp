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

// Helper functions to get the edges of the sprite
float Entity::left() const noexcept
{
    auto box = getBoundingBox();
    return x() - box.width/2.0f;
}

float Entity::right() const noexcept
{
    auto box = getBoundingBox();
    return x() + box.width/2.0f;
}

float Entity::top() const noexcept
{
    auto box = getBoundingBox();
    return y() - box.height/2.0f;
}

float Entity::bottom() const noexcept
{
    auto box = getBoundingBox();
    return y() + box.height/2.0f;
}

// Helpoer functions for the state of the entity
void Entity::destroy() noexcept { destroyed = true; }
bool Entity::isDestroyed() const noexcept { return destroyed; }