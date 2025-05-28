#include "upgrades.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

sf::FloatRect purchaseBoundingBox;

int ID;

std::vector<bool> boughtUpgrade = { false, false, false, false, false };

int checkIfPurchasable(float X, float Y, sf::FloatRect mouseBoundingBox) {

    purchaseBoundingBox.position = (sf::Vector2f(X, Y));

    if (purchaseBoundingBox.position.y == 750.f) { ID = 0; }
    else { ID = (purchaseBoundingBox.position.y - 750.f) / 150.f; }

    if (mouseClicked && purchaseBoundingBox.findIntersection(mouseBoundingBox) && cookieDisplay >= prices.at(ID)) {

        cookies -= (prices.at(ID));

        if (prices.at(ID) < 1000) {prices[ID] = prices.at(ID) * 1.1f;}
        else if (prices.at(ID) < 100000) {prices[ID] = prices.at(ID) * 1.075f;}
        else { prices[ID] = prices.at(ID) * 1.05f; }

        amount[ID] = amount.at(ID) += 1;

        switch (ID + 1) {
        case 1:
            cpc++;
            break;
        case 2:
            cps += 5.f;
            break;
        case 3:
            cps += 75.f;
            cpc++;
            break;
        case 4:
            cps += 1000.f;
            cpc += 5.f;
            break;
        case 5:
            cps += 15000.f;
            cpc += 75.f;
            break;
        }
    }
    return prices.at(ID);
}

void checkIfUpgradable(float X, float Y, sf::FloatRect mouseBoundingBox, short upgradeID) {
    purchaseBoundingBox.position = (sf::Vector2f(X, Y));

    if (mouseClicked && purchaseBoundingBox.findIntersection(mouseBoundingBox)) {

        switch (upgradeID + 1) {
        case 1:
            if (cookies >= 1000) {
                cookies -= 1000;
                boughtUpgrade.at(0) = true;
            }
            clickMultiplier += 1;
            break;
        case 2:
            if (cookies >= 2000) {
                cookies -= 2000;
                boughtUpgrade.at(1) = true;
            }
            cpsMultiplier += 1;
            break;
        case 3:
            if (cookies >= 5000) {
                cookies -= 5000;
                boughtUpgrade.at(2) = true;
            }
            cpsMultiplier += 1;
            break;
        case 4:
            if (cookies >= 10000) {
                cookies -= 10000;
                boughtUpgrade.at(3) = true;
            }
            cpsMultiplier += 1;
            break;
        case 5:
            if (cookies >= 50000) {
                cookies -= 50000;
                boughtUpgrade.at(4) = true;
            }
            cpsMultiplier += 1;
            clickMultiplier += 1;
            break;
        }
    }
}

void simulateUpgrades(sf::RenderWindow& window, sf::FloatRect mouseBoundingBox, sf::Sprite cursor, sf::Sprite grandma, sf::Sprite farm, sf::Sprite mine, sf::Sprite factory, sf::Text cursorCost, sf::Text grandmaCost, sf::Text farmCost, sf::Text mineCost, sf::Text factoryCost, sf::Sprite clicksUpgrade, sf::Sprite grandmaUpgrade, sf::Sprite farmUpgrade, sf::Sprite cpsUpgrade) {

    
	purchaseBoundingBox.size = (sf::Vector2f(120.f, 120.f));

    window.draw(cursor);
    cursorCost.setString(std::to_string(checkIfPurchasable(2720.f, 750.f, mouseBoundingBox)));
    window.draw(cursorCost);
    if (!boughtUpgrade.at(0)) {
        if (amount.at(0) > 10) {
            checkIfUpgradable(2100.f, 300.f, mouseBoundingBox, 0);
            window.draw(clicksUpgrade);
        }
    }
    window.draw(grandma);
    grandmaCost.setString(std::to_string(checkIfPurchasable(2720.f, 900.f, mouseBoundingBox)));
    window.draw(grandmaCost);
    if (!boughtUpgrade.at(1)) {
        if (amount.at(1) > 10) {
            checkIfUpgradable(2250.f, 300.f, mouseBoundingBox, 1);
            window.draw(grandmaUpgrade);
        }
    }
    window.draw(farm);
    farmCost.setString(std::to_string(checkIfPurchasable(2720.f, 1050.f, mouseBoundingBox)));
    window.draw(farmCost);
    if (!boughtUpgrade.at(2)) {
        if (amount.at(2) > 10) {
            checkIfUpgradable(2400.f, 300.f, mouseBoundingBox, 2);
            window.draw(farmUpgrade);
        }
    }
    window.draw(mine);
    mineCost.setString(std::to_string(checkIfPurchasable(2720.f, 1200.f, mouseBoundingBox)));
    window.draw(mineCost);
    window.draw(factory);
    factoryCost.setString(std::to_string(checkIfPurchasable(2720.f, 1350.f, mouseBoundingBox)));
    window.draw(factoryCost);

    if (!boughtUpgrade.at(3)) {
        if (cps > 10000) {
            checkIfUpgradable(2550.f, 300.f, mouseBoundingBox, 3);
            window.draw(cpsUpgrade);
        }
    }
}