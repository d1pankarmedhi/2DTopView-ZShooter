#include "Player.h"

// constructor
Player::Player()
    : m_Speed(START_SPEED),
      m_Health(START_HEALTH),
      m_MaxHealth(START_HEALTH),
      m_Texture(),
      m_Sprite()
{
    // load texture and set origin
    m_Texture.loadFromFile("graphics/player.png");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setOrigin(25, 25);
}

// Player spawn
Player::spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize)
{
    // place at the middle of screen
    m_Position.x = arena.width / 2;
    m_Position.y = arena.height / 2;

    m_Arena.left = arena.left;
    m_Arena.width = arena.width;
    m_Arena.top = arena.top;
    m_Arena.height = arena.height;
    m_TileSize = tileSize;

    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;
}

// reset when player dies
void Player::resetPlayerStats()
{
    m_Speed = START_SPEED;
    m_Health = START_HEALTH;
    m_MaxHealth = START_HEALTH;
}

// get last hit time
Time Player::getLastHitTime()
{
    return m_LastHit;
}

// handle when player it hit
bool Player::hit(Time timeHit)
{
    // check if time passed in is 200 milliseconds ahead than last hit
    if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)
    {
        m_LastHit = timeHit;
        m_Health -= 10;
        return true;
    }
    else
    {
        return false;
    }
}

ct Player::getPosition()
{
    return m_Sprite.getGlobalBounds();
}
Vector2f Player::getCenter()
{
    return m_Position;
}
float Player::getRotation()
{
    return m_Sprite.getRotation();
}
Sprite Player::getSprite()
{
    return m_Sprite;
}
int Player::getHealth()
{
    return m_Health;
}

// movement
void Player::moveLeft()
{
    m_LeftPressed = true;
}
ayer::moveRight()
{
    m_RightPressed = true;
}
void Player::moveUp()
{
    m_UpPressed = true;
}
void Player::moveDown()
{
    m_DownPressed = true;
}
void Player::stopLeft()
{
    m_LeftPressed = false;
}
void Player::stopRight()
{
    m_RightPressed = false;
}
void Player::stopUp()
{
    m_UpPressed = false;
}
void Player::stopDown()
{
    m_DownPressed = false;
}

// Update player per frame
::update(float elapsedTime, sf::Vector2i mousePosition)
{
    // update player movement
    if (m_UpPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }
    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }
    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }
    m_Sprite.setPosition(m_Position);

    // Keep the player in the arena
    if (m_Position.x > m_Arena.width - m_TileSize)
    {
        m_Position.x = m_Arena.width - m_TileSize;
    }
    if (m_Position.x < m_Arena.left + m_TileSize)
    {
        m_Position.x = m_Arena.left + m_TileSize;
    }
    if (m_Position.y > m_Arena.height - m_TileSize)
    {
        m_Position.y = m_Arena.height - m_TileSize;
    }
    if (m_Position.y < m_Arena.top + m_TileSize)
    {
        m_Position.y = m_Arena.top + m_TileSize;
    }

    // Calculate the angle the player is facing
    // find angle between mouse and screen center
    float angle = (atan2(mousePosition.y - m_Resolution.y / 2, mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;
    // set player angle
    m_Sprite.setRotation(angle);
}

// Player Upgrades
void Player::upgradeSpeed()
{
    // 20% speed upgrade
    m_Speed += (START_SPEED * .2);
}
void Player::upgradeHealth()
{
    // 20% max health upgrade
    m_MaxHealth += (START_HEALTH * .2);
}
// pickup upgrade
void Player::increaseHealthLevel(int amount)
{
    m_Health += amount;
    // But not beyond the maximum
    if (m_Health > m_MaxHealth)
    {
        m_Health = m_MaxHealth;
    }
}