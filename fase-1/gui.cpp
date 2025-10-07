#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
// this will go in main.cpp

int main() {

    vector<sf::Sprite> elements;

    sf::RenderWindow win(sf::VideoMode(800, 600), "CozinhaDAComp");
    win.setFramerateLimit(30);

    sf::Texture comanda_texture;
    if (!comanda_texture.loadFromFile("./sprites/Comanda.png")) {
        return -1;
    }

    sf::Sprite comanda;
    comanda.setTexture(comanda_texture);
    comanda.setPosition(sf::Vector2f(100, 500));
    comanda.setScale(sf::Vector2f(0.5f, 0.5f));
    sf::FloatRect comanda_colision = comanda.getGlobalBounds();
    sf::Color originalComanda = comanda.getColor();

    sf::Texture cozinha_texture;
    if (!cozinha_texture.loadFromFile("./sprites/prot_coz.jpeg")) {
        return -1;
    }

    sf::Sprite cozinha;
    cozinha.setTexture(cozinha_texture);
    cozinha.setPosition(sf::Vector2f(0, 0));
    cozinha.setScale(sf::Vector2f(0.75f, 1.0f));

    sf::Texture tomate_texture;
    if (!tomate_texture.loadFromFile("./sprites/Tomate.png")) {
        return -1;
    }
    sf::Sprite tomate;
    tomate.setTexture(tomate_texture);
    tomate.setPosition(sf::Vector2f(90, 450));
    tomate.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect tomate_colision = tomate.getGlobalBounds();
    sf::Color originalTomate = tomate.getColor();

    sf::Texture alface_texture;
    if (!alface_texture.loadFromFile("./sprites/Alface.png")) {
        return -1;
    }
    sf::Sprite alface;
    alface.setTexture(alface_texture);
    alface.setPosition(sf::Vector2f(90, 300));
    alface.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect alface_colision = alface.getGlobalBounds();
    sf::Color originalAlface = alface.getColor();

    sf::Texture bacon_texture;
    if (!bacon_texture.loadFromFile("./sprites/Bacon.png")) {
        return -1;
    }
    sf::Sprite bacon;
    bacon.setTexture(bacon_texture);
    bacon.setPosition(sf::Vector2f(90, 150));
    bacon.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect bacon_colision = bacon.getGlobalBounds();
    sf::Color originalBacon = bacon.getColor();

    sf::Texture brioche_texture;
    if (!brioche_texture.loadFromFile("./sprites/Brioche.png")) {
        return -1;
    }
    sf::Sprite brioche;
    brioche.setTexture(brioche_texture);
    brioche.setPosition(sf::Vector2f(300, 50));
    brioche.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect brioche_colision = brioche.getGlobalBounds();
    sf::Color originalBrioche = brioche.getColor();

    sf::Texture cebola_car_texture;
    if (!cebola_car_texture.loadFromFile("./sprites/Cebola_Car.png")) {
        return -1;
    }
    sf::Sprite cebola_car;
    cebola_car.setTexture(cebola_car_texture);
    cebola_car.setPosition(sf::Vector2f(400, 50));
    cebola_car.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect cebola_car_colision = cebola_car.getGlobalBounds();
    sf::Color originalCebola_Car = cebola_car.getColor();

    sf::Texture cebola_nor_texture;
    if (!cebola_nor_texture.loadFromFile("./sprites/Cebola_Nor.png")) {
        return -1;
    }
    sf::Sprite cebola_nor;
    cebola_nor.setTexture(cebola_nor_texture);
    cebola_nor.setPosition(sf::Vector2f(500, 50));
    cebola_nor.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect cebola_nor_colision = cebola_nor.getGlobalBounds();
    sf::Color originalCebola_Nor = cebola_nor.getColor();

    sf::Texture frango_texture;
    if (!frango_texture.loadFromFile("./sprites/Frango.png")) {
        return -1;
    }
    sf::Sprite frango;
    frango.setTexture(frango_texture);
    frango.setPosition(sf::Vector2f(660, 475));
    frango.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect frango_colision = frango.getGlobalBounds();
    sf::Color originalFrango = frango.getColor();

    sf::Texture hamburguer_bov_texture;
    if (!hamburguer_bov_texture.loadFromFile("./sprites/Hamburguer_Bov.png")) {
        return -1;
    }
    sf::Sprite hamburguer_bov;
    hamburguer_bov.setTexture(hamburguer_bov_texture);
    hamburguer_bov.setPosition(sf::Vector2f(660, 325));
    hamburguer_bov.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect hamburguer_bov_colision = hamburguer_bov.getGlobalBounds();
    sf::Color originalHamburguer_Bov = hamburguer_bov.getColor();

    sf::Texture hamburguer_veg_texture;
    if (!hamburguer_veg_texture.loadFromFile("./sprites/Hamburguer_Veg.png")) {
        return -1;
    }
    sf::Sprite hamburguer_veg;
    hamburguer_veg.setTexture(hamburguer_veg_texture);
    hamburguer_veg.setPosition(sf::Vector2f(650, 175));
    hamburguer_veg.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect hamburguer_veg_colision = hamburguer_veg.getGlobalBounds();
    sf::Color originalHamburguer_Veg = hamburguer_veg.getColor();

    sf::Texture ketchup_texture;
    if (!ketchup_texture.loadFromFile("./sprites/Ketchup.png")) {
        return -1;
    }
    sf::Sprite ketchup;
    ketchup.setTexture(ketchup_texture);
    ketchup.setPosition(sf::Vector2f(300, 300));
    ketchup.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect ketchup_colision = ketchup.getGlobalBounds();
    sf::Color originalKetchup = ketchup.getColor();

    sf::Texture mustard_texture;
    if (!mustard_texture.loadFromFile("./sprites/Mustard.png")) {
        return -1;
    }
    sf::Sprite mustard;
    mustard.setTexture(mustard_texture);
    mustard.setPosition(sf::Vector2f(400, 300));
    mustard.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect mustard_colision = mustard.getGlobalBounds();
    sf::Color originalMustard = mustard.getColor();

    sf::Texture pao_texture;
    if (!pao_texture.loadFromFile("./sprites/Pao_hamb.png")) {
        return -1;
    }
    sf::Sprite pao;
    pao.setTexture(pao_texture);
    pao.setPosition(sf::Vector2f(500, 300));
    pao.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect pao_colision = pao.getGlobalBounds();
    sf::Color originalPao = pao.getColor();

    elements.push_back(tomate);
    elements.push_back(alface);
    elements.push_back(bacon);
    elements.push_back(brioche);
    elements.push_back(cebola_car);
    elements.push_back(cebola_nor);
    elements.push_back(frango);
    elements.push_back(hamburguer_bov);
    elements.push_back(hamburguer_veg);
    elements.push_back(ketchup);
    elements.push_back(mustard);
    elements.push_back(pao);

    //Window loop
    bool pedido = false;
    sf::Vector2i cursorPosition = sf::Mouse::getPosition(win);
    sf::Vector2f worldPos = win.mapPixelToCoords(cursorPosition);
    while (win.isOpen()) {
        //Event Info Getting Section
        cursorPosition = sf::Mouse::getPosition(win);
        worldPos = win.mapPixelToCoords(cursorPosition);
        sf::Event e;
        //cout << worldPos.x << " | " << worldPos.y << endl;
        //Event loop
        while (win.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                win.close();
            }

            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::G) {
                    pedido = true;
                }

                if (e.key.code == sf::Keyboard::Enter) {
                    pedido = false;
                }
            }

            if (e.type == sf::Event::MouseButtonPressed) {
                if (e.mouseButton.button == sf::Mouse::Left) {
                    if (tomate_colision.contains(worldPos)) {
                        cout << "Escolheu tomate" << endl;
                    }

                    if (alface_colision.contains(worldPos)) {
                        cout << "Escolheu alface" << endl;
                    }

                    if (bacon_colision.contains(worldPos)) {
                        cout << "Escolheu bacon" << endl;
                    }

                    if (brioche_colision.contains(worldPos)) {
                        cout << "Escolheu brioche" << endl;
                    }

                    if (cebola_car_colision.contains(worldPos)) {
                        cout << "Escolheu cebola_car" << endl;
                    }

                    if (cebola_nor_colision.contains(worldPos)) {
                        cout << "Escolheu cebola_nor" << endl;
                    }

                    if (frango_colision.contains(worldPos)) {
                        cout << "Escolheu frango" << endl;
                    }

                    if (hamburguer_bov_colision.contains(worldPos)) {
                        cout << "Escolheu hamburguer_bov" << endl;
                    }

                    if (hamburguer_veg_colision.contains(worldPos)) {
                        cout << "Escolheu hamburguer_veg" << endl;
                    }

                    if (ketchup_colision.contains(worldPos)) {
                        cout << "Escolheu ketchup" << endl;
                    }

                    if (mustard_colision.contains(worldPos)) {
                        cout << "Escolheu mustard" << endl;
                    }

                    if (pao_colision.contains(worldPos)) {
                        cout << "Escolheu pao" << endl;
                    }

                    if (comanda_colision.contains(worldPos) && pedido) {
                        cout << "Escolheu comanda" << endl;
                    }
                }
            }
        }

        if (tomate_colision.contains(worldPos)) {
            cout << "tom";
            tomate.setColor(sf::Color::Blue);
        } else {
            tomate.setColor(originalTomate);
        }

        if (alface_colision.contains(worldPos)) {
            alface.setColor(sf::Color::Blue);
        } else {
            alface.setColor(originalAlface);
        }

        if (bacon_colision.contains(worldPos)) {
            bacon.setColor(sf::Color::Blue);
        } else {
            bacon.setColor(originalBacon);
        }

        if (brioche_colision.contains(worldPos)) {
            brioche.setColor(sf::Color::Blue);
        } else {
            brioche.setColor(originalBrioche);
        }

        if (cebola_car_colision.contains(worldPos)) {
            cebola_car.setColor(sf::Color::Blue);
        } else {
            cebola_car.setColor(originalCebola_Car);
        }

        if (cebola_nor_colision.contains(worldPos)) {
            cebola_nor.setColor(sf::Color::Blue);
        } else {
            cebola_nor.setColor(originalCebola_Nor);
        }

        if (frango_colision.contains(worldPos)) {
            frango.setColor(sf::Color::Blue);
        } else {
            frango.setColor(originalFrango);
        }

        if (hamburguer_bov_colision.contains(worldPos)) {
            hamburguer_bov.setColor(sf::Color::Blue);
        } else {
            hamburguer_bov.setColor(originalHamburguer_Bov);
        }

        if (hamburguer_veg_colision.contains(worldPos)) {
            hamburguer_veg.setColor(sf::Color::Blue);
        } else {
            hamburguer_veg.setColor(originalHamburguer_Veg);
        }

        if (ketchup_colision.contains(worldPos)) {
            ketchup.setColor(sf::Color::Blue);
        } else {
            ketchup.setColor(originalKetchup);
        }

        if (mustard_colision.contains(worldPos)) {
            mustard.setColor(sf::Color::Blue);
        } else {
            mustard.setColor(originalMustard);
        }

        if (pao_colision.contains(worldPos)) {
            pao.setColor(sf::Color::Blue);
        } else {
            pao.setColor(originalPao);
        }
        
        //drawloop
        win.clear(sf::Color::Black);
        win.draw(cozinha);
        if (pedido) {
            if (comanda_colision.contains(worldPos)) {
                comanda.setColor(sf::Color::Blue);
            } else {
                comanda.setColor(originalComanda);
            }
            win.draw(comanda);
        }
        for (sf::Sprite s : elements) {
            win.draw(s);
        }
        win.display();
    }
}


