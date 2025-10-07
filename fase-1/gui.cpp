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
    if (!cozinha_texture.loadFromFile("./sprites/prot_coz.png")) {
        return -1;
    }

    sf::Sprite cozinha;
    cozinha.setTexture(cozinha_texture);
    cozinha.setPosition(sf::Vector2f(0, 0));
    cozinha.setScale(sf::Vector2f(0.6f, 0.81f));

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

    sf::Texture base_brioche_texture;
    if (!base_brioche_texture.loadFromFile("./sprites/Base_Brioche.png")) {
        return -1;
    }
    sf::Sprite base_brioche;
    base_brioche.setTexture(base_brioche_texture);
    base_brioche.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect base_brioche_colision = base_brioche.getGlobalBounds();
    sf::Color originalbase_Brioche = base_brioche.getColor();

    sf::Texture topo_brioche_texture;
    if (!topo_brioche_texture.loadFromFile("./sprites/Topo_Brioche.png")) {
        return -1;
    }
    sf::Sprite topo_brioche;
    topo_brioche.setTexture(topo_brioche_texture);
    topo_brioche.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect topo_brioche_colision = topo_brioche.getGlobalBounds();
    sf::Color originaltopo_Brioche = topo_brioche.getColor();

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
    if (!pao_texture.loadFromFile("./sprites/Pao.png")) {
        return -1;
    }
    sf::Sprite pao;
    pao.setTexture(pao_texture);
    pao.setPosition(sf::Vector2f(500, 300));
    pao.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect pao_colision = pao.getGlobalBounds();
    sf::Color originalpao = pao.getColor();

    sf::Texture base_pao_texture;
    if (!base_pao_texture.loadFromFile("./sprites/Base_Pao.png")) {
        return -1;
    }
    sf::Sprite base_pao;
    base_pao.setTexture(base_pao_texture);
    base_pao.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect base_pao_colision = base_pao.getGlobalBounds();
    sf::Color originalbase_pao = base_pao.getColor();

    sf::Texture topo_pao_texture;
    if (!topo_pao_texture.loadFromFile("./sprites/Topo_Pao.png")) {
        return -1;
    }
    sf::Sprite topo_pao;
    topo_pao.setTexture(topo_pao_texture);
    topo_pao.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect topo_pao_colision = topo_pao.getGlobalBounds();
    sf::Color originaltopo_pao = topo_pao.getColor();

    sf::Sprite* Dragged;

    //Window loop
    bool pedido = false;
    int bread_type = -1;
    bool bread_base = false;
    float layer_offset = 0;
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
                    elements.clear();
                    pedido = false;
                    bread_type = -1;
                    bread_base = false;
                }
            }

            if (e.type == sf::Event::MouseButtonPressed) {
                if (e.mouseButton.button == sf::Mouse::Left) {
                    if (tomate_colision.contains(worldPos)) {
                        tomate.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(tomate);
                    }

                    if (alface_colision.contains(worldPos)) {
                        alface.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(alface);
                    }

                    if (bacon_colision.contains(worldPos)) {
                        bacon.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(bacon);
                    }

                    if (brioche_colision.contains(worldPos) && (bread_type == 1 | bread_type == -1)) {
                        bread_type = 1;
                        if (!bread_base) {
                            base_brioche.setPosition(sf::Vector2f(425, 500 - layer_offset));
                            elements.push_back(base_brioche);
                        } else {
                            topo_brioche.setPosition(sf::Vector2f(425, 500 - layer_offset));
                            elements.push_back(topo_brioche);
                        }

                        if (!bread_base) {
                            bread_base = true;
                        }

                        layer_offset += 6.5f;                        
                    }

                    if (cebola_car_colision.contains(worldPos)) {
                        cebola_car.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(cebola_car);
                    }

                    if (cebola_nor_colision.contains(worldPos)) {
                        cebola_nor.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(cebola_nor);
                    }

                    if (frango_colision.contains(worldPos)) {
                        frango.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(frango);
                    }

                    if (hamburguer_bov_colision.contains(worldPos)) {
                        hamburguer_bov.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(hamburguer_bov);
                    }

                    if (hamburguer_veg_colision.contains(worldPos)) {
                        hamburguer_veg.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(hamburguer_veg);
                    }

                    if (ketchup_colision.contains(worldPos)) {
                        ketchup.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(ketchup);
                    }

                    if (mustard_colision.contains(worldPos)) {
                        mustard.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(mustard);
                    }

                    if (pao_colision.contains(worldPos) && (bread_type == 0 | bread_type == -1)) {
                        bread_type = 0;

                        if (!bread_base) {
                            base_pao.setPosition(sf::Vector2f(425, 500 - layer_offset));
                            elements.push_back(base_pao);
                        } else {
                            topo_pao.setPosition(sf::Vector2f(425, 500 - layer_offset));
                            elements.push_back(topo_pao);
                        }

                        if (!bread_base) {
                            bread_base = true;
                        }

                        layer_offset += 6.5f;
                    }

                    if (comanda_colision.contains(worldPos) && pedido) {
                        cout << "Escolheu comanda" << endl;
                    }
                }
            }
        }

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


