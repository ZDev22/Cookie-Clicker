#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML window");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()){if (event->is<sf::Event::Closed>())window.close();}

        window.clear();
        window.display();
    }
}