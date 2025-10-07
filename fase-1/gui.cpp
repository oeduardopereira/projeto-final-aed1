#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;





// this will go in main.cpp

int main() {
    sf::RenderWindow win(sf::VideoMode(800, 600), "GameWindow");
    win.setFramerateLimit(30);

    //Window loop
    while (win.isOpen()) {

        sf::Event e;

        //Event loop
        while (win.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                win.close();
            }
        }

        win.clear(sf::Color::Black);
        win.display();

    }

}


