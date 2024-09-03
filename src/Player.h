#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    const float START_SPEED = 200;
    const float START_HEALTH = 100;

    // player config
    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
    sf::Vector2f m_Resolution;
    sf::IntRect m_Arena;
    int m_TileSize;
    // player direction
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;
    // present health
    int m_Health;
    // max health player can have
    int m_MaxHealth;

    sf::Time m_LastHit;

    float m_Speed;

public:
    Player();
    void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);
    void resetPlayerStats();
    // handle player getting hit by zombie
    bool hit(sf::Time timeHit);
    sf::Time getLastHitTime();
    // player position
    sf::FloatRect getPostition();
    // player center
    sf::Vector2f getCenter();
    // player facing angle
    float getRotation();
    // send sprite to main function
    sf::Sprite getSprite();
    // player movement
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    // stop player
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    // update player on screen
    void update(float elapsedTime, sf::Vector2f mousePosition);
    // speed boost
    void upgradeSpeed();
    // upgrade health
    void upgradeHealth();
    // upgrade max heath
    void increaseHealthLevel(int amount);
    // current health
    void getHealth();
}