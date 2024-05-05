#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    unsigned int screenWidth = desktopMode.width;

    unsigned int screenHeight = desktopMode.height;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "KOS Game");

    sf::CircleShape shape(100.f);
    sf::CircleShape shaper(100.f);
    shape.setFillColor(sf::Color::Yellow);
    shaper.setFillColor(sf::Color::Green);

    int speed = 15;
    sf::Clock clock;
    float felapsed = 0;
    sf::Vector2f dir(1, 0);
    int x = 100;
    int y = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if ( x + 100 < screenWidth ) {
            x+=100;
        }
        shape.setPosition(x, y );

        shaper.setPosition(200, 400 );
        sf::Time duration = sf::microseconds(10000);
        sf::sleep(duration);


        window.clear();
        window.draw(shape);
        window.draw(shaper);
        window.display();

        if ( x == 1000 ) {
            x = 0;
        }
    }
    return 0;
}
