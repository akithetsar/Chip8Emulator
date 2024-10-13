
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {sf::Clock clock; // starts the clock


    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.scancode == sf::Keyboard::Scan::Escape)
                {
                    std::cout << "the escape key was pressed" << std::endl;
                    std::cout << "scancode: " << event.key.scancode << std::endl;
                    std::cout << "code: " << event.key.code << std::endl;
                    std::cout << "control: " << event.key.control << std::endl;
                    std::cout << "alt: " << event.key.alt << std::endl;
                    std::cout << "shift: " << event.key.shift << std::endl;
                    std::cout << "system: " << event.key.system << std::endl;
                    std::cout << "description: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << std::endl;
                    std::cout << "localize: " << sf::Keyboard::localize(event.key.scancode) << std::endl;
                    std::cout << "delocalize: " << sf::Keyboard::delocalize(event.key.code) << std::endl;
                }
            }
        }
    }
    return 0;
}

