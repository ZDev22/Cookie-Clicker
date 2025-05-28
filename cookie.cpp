#include "cookie.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

float targetSize;
float size = .2f;

sf::FloatRect cookieBoundingBox;

float tween(float current, float target) { return current + (target - current) * .2f; }

sf::Sprite simulateCookie(sf::Sprite cookie, sf::FloatRect mouseBoundingBox) {

	targetSize = .2f;

	cookieBoundingBox.size = (sf::Vector2f(550.f, 600.f));
	cookieBoundingBox.position = (sf::Vector2f(180.f, 520.f));

    if (mouseBoundingBox.findIntersection(cookieBoundingBox)) {
        
        targetSize += 0.05f;

        if (mouseClicked) {
           cookies += cpc * clickMultiplier;
           targetSize += 0.15f;
        }
    }

	size = tween(size, targetSize);
	cookie.scale(sf::Vector2f(size, size));

	return cookie;
}