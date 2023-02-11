#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Game;
class CollisionObject;
class GameState
{
public:
    virtual void handleEvents(sf::RenderWindow &window) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow &window) = 0;

    sf::View camera;
protected:
    void smoothCameraFollow(const sf::Vector2f &objectPosition,
                            const float deltaTime,
                            const float cameraSpeed) {
        sf::Vector2f cameraCenter = this->camera.getCenter();
        sf::Vector2f newCameraCenter = cameraCenter + (objectPosition - cameraCenter) * cameraSpeed;
        this->camera.setCenter(newCameraCenter);
    }
};
