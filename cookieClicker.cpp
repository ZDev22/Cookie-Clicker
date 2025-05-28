#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "cookie.hpp"
#include "upgrades.hpp"
#include "milk.hpp"
#include <string>
#include <iostream>

float cookies = 0.f;
long long cookieDisplay = 0;
long long cpc = 1;
long long cps = 0;

bool mouseClicked = false;
bool mousePressed = false;

int clickMultiplier = 1.f;
int cpsMultiplier = 1.f;

std::vector<float> prices = { 10.f, 100.f, 1000.f, 10000.f, 100000.f, 0.f };
std::vector<int> amount = { 0, 0, 0, 0, 0, 0 };

sf::FloatRect mouseBoundingBox;

int main() {

    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "SFML window");
    window.setFramerateLimit(60);

    const sf::Font arvoRegular("Arvo-Regular.ttf");

    sf::Text cookieAmount(arvoRegular, "0", 50);
    cookieAmount.setFillColor(sf::Color(0, 0, 0));
    cookieAmount.setPosition(sf::Vector2f(10.f, 10.f));
    sf::Text cookiesPerClick(arvoRegular, "1", 50);
    cookiesPerClick.setFillColor(sf::Color(0, 0, 0));
    cookiesPerClick.setPosition(sf::Vector2f(10.f, 70.f));
    sf::Text cookiesPerSecond(arvoRegular, "1", 50);
    cookiesPerSecond.setFillColor(sf::Color(0, 0, 0));
    cookiesPerSecond.setPosition(sf::Vector2f(10.f, 130.f));

    //sf::Music music("nice_music.ogg");
    //music.play();

    sf::Texture cookieTexture("cookie.png");
    sf::Texture backgroundTexture("background.png");
    sf::Texture cursorTexture("cursor.png");
    sf::Texture grandmaTexture("Grandma.png");
    sf::Texture farmTexture("farm.png");
    sf::Texture mineTexture("mine.png");
    sf::Texture factoryTexture("factory.png");

    sf::Texture clicksUpgradeTexture("clicksX2.jpg");
    sf::Texture grandmaUpgradeTexture("grandmasX2.jpg");
    sf::Texture farmUpgradeTexture("farmsX2.jpg");
    sf::Texture cpsUpgradeTexture("cpsX2.jpg");

    sf::Texture milkTexture("milk.png");
	sf::Sprite milk(milkTexture);

    sf::Sprite cookie(cookieTexture);
    cookie.setPosition(sf::Vector2f(120.f, 250.f));
    cookie.setOrigin(sf::Vector2f(250.f, 250.f));

    sf::Sprite background(backgroundTexture);
    background.setScale(sf::Vector2f(.25f, .25f));

    sf::Sprite cursor(cursorTexture);
    cursor.setPosition(sf::Vector2f(900.f, 250.f));
    cursor.setScale(sf::Vector2f(.12f, .12f));
    sf::Text cursorCost(arvoRegular, "1", 50);
    cursorCost.setFillColor(sf::Color(0, 0, 0));
    cursorCost.setPosition(sf::Vector2f(950.f, 260.f));
    cursorCost.setScale(sf::Vector2f(.45f, .45f));

    sf::Sprite grandma(grandmaTexture);
    grandma.setPosition(sf::Vector2f(900.f, 298.f));
    grandma.setScale(sf::Vector2f(.12f, .12f));
    sf::Text grandmaCost(arvoRegular, "1", 50);
    grandmaCost.setFillColor(sf::Color(0, 0, 0));
    grandmaCost.setPosition(sf::Vector2f(950.f, 308.f));
    grandmaCost.setScale(sf::Vector2f(.45f, .45f));

    sf::Sprite farm(farmTexture);
    farm.setPosition(sf::Vector2f(900.f, 346.f));
    farm.setScale(sf::Vector2f(.12f, .12f));
    sf::Text farmCost(arvoRegular, "1", 50);
    farmCost.setFillColor(sf::Color(0, 0, 0));
    farmCost.setPosition(sf::Vector2f(950.f, 356.f));
    farmCost.setScale(sf::Vector2f(.45f, .45f));

    sf::Sprite mine(mineTexture);
    mine.setPosition(sf::Vector2f(900.f, 394.f));
    mine.setScale(sf::Vector2f(.12f, .12f));
    sf::Text mineCost(arvoRegular, "1", 50);
    mineCost.setFillColor(sf::Color(0, 0, 0));
    mineCost.setPosition(sf::Vector2f(950.f, 414.f));
    mineCost.setScale(sf::Vector2f(.45f, .45f));

    sf::Sprite factory(factoryTexture);
    factory.setPosition(sf::Vector2f(900.f, 442.f));
    factory.setScale(sf::Vector2f(.12f, .12f));
    sf::Text factoryCost(arvoRegular, "1", 50);
    factoryCost.setFillColor(sf::Color(0, 0, 0));
    factoryCost.setPosition(sf::Vector2f(950.f, 452.f));
    factoryCost.setScale(sf::Vector2f(.45f, .45f));

    sf::Sprite clicksUpgrade(clicksUpgradeTexture);
    clicksUpgrade.setPosition(sf::Vector2f(700.f, 100.f));
    clicksUpgrade.setScale(sf::Vector2f(.12f, .12f));
    sf::Sprite grandmaUpgrade(grandmaUpgradeTexture);
    grandmaUpgrade.setPosition(sf::Vector2f(750.f, 100.f));
    grandmaUpgrade.setScale(sf::Vector2f(.12f, .12f));
    sf::Sprite farmUpgrade(farmUpgradeTexture);
    farmUpgrade.setPosition(sf::Vector2f(800.f, 100.f));
    farmUpgrade.setScale(sf::Vector2f(.12f, .12f));
    sf::Sprite cpsUpgrade(cpsUpgradeTexture);
    cpsUpgrade.setPosition(sf::Vector2f(850.f, 100.f));
    cpsUpgrade.setScale(sf::Vector2f(.12f, .12f));

    while (window.isOpen()){

        while (const std::optional event = window.pollEvent()){if (event->is<sf::Event::Closed>()) {window.close();}}

        mouseBoundingBox.size = (sf::Vector2f(5.f, 5.f));
        mouseBoundingBox.position = (sf::Vector2f(static_cast<float>(sf::Mouse::getPosition().x), static_cast<float>(sf::Mouse::getPosition().y)));


        window.clear();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (!mousePressed) { mouseClicked = true; }
            else { mouseClicked = false; }
            mousePressed = true;
        }
        else { mousePressed = false; }

        window.draw(background);
        window.draw(simulateCookie(cookie, mouseBoundingBox));

        cookies += static_cast<float>(cps * clickMultiplier) / 60.f;
        cookieDisplay = cookies;

        cookieAmount.setString("Cookies: " + std::to_string(cookieDisplay));
        cookiesPerClick.setString("CPC: " + std::to_string(cpc));
        cookiesPerSecond.setString("CPS: " + std::to_string(cps));
        window.draw(cookieAmount);
        window.draw(cookiesPerClick);
        window.draw(cookiesPerSecond);

        simulateUpgrades(window, mouseBoundingBox, cursor, grandma, farm, mine, factory, cursorCost, grandmaCost, farmCost, mineCost, factoryCost, clicksUpgrade, grandmaUpgrade, farmUpgrade, cpsUpgrade);
		if (simulateMilk(window, milk)) {
            return 0;
		}

        window.display();
    }
}