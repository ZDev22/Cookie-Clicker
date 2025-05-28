#ifndef	UPGRADES_HPP
#define UPGRADES_HPP

#include "cookieClicker.hpp"
#include "SFML/Graphics.hpp"

void simulateUpgrades(sf::RenderWindow& window, sf::FloatRect mouseBoundingBox, sf::Sprite cursor, sf::Sprite grandma, sf::Sprite farm, sf::Sprite mine, sf::Sprite factory, sf::Text cursorCost, sf::Text grandmaCost, sf::Text farmCost, sf::Text mineCost, sf::Text factoryCost, sf::Sprite clicksUpgrade, sf::Sprite grandmaUpgrade, sf::Sprite farmUpgrade, sf::Sprite cpsUpgrade);

#endif