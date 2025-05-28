#include "milk.hpp"
#include <iostream>

bool simulateMilk(sf::RenderWindow& window, sf::Sprite milk) {
	milk.setPosition(sf::Vector2f(0.f, (695.f - (cookies / 100000))));
	milk.setScale(sf::Vector2f(.3f, .3f));
	window.draw(milk);

	if (milk.getPosition().y < 300.f) {return true;}
	return false;
}