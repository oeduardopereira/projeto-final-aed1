#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>

#include "Receita.h"
#include "pilha.h"
#include "Ingrediente.h"
#include "constantes.h"
#include "utils.h"

using namespace std;

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

    sf::Texture comanda_aberta_texture;
    if (!comanda_aberta_texture.loadFromFile("./sprites/Comanda_Aberta.png")) {
        return -1;
    }

    sf::Sprite comanda_aberta;
    comanda_aberta.setTexture(comanda_aberta_texture);
    comanda_aberta.setScale(sf::Vector2f(0.8f, 0.8f));
    sf::FloatRect comanda_aberta_colision = comanda_aberta.getGlobalBounds();
    sf::Color originalComanda_aberta = comanda_aberta.getColor();

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
    tomate.setScale(sf::Vector2f(0.25f, 0.25f));
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
    topo_brioche.setScale(sf::Vector2f(0.4f, 0.4f));
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
    topo_pao.setScale(sf::Vector2f(0.4f, 0.4f));
    sf::FloatRect topo_pao_colision = topo_pao.getGlobalBounds();
    sf::Color originaltopo_pao = topo_pao.getColor();

    sf::Font font;
    font.loadFromFile("./assets/font.ttf");


    sf::Text timerText;
    timerText.setFont(font);
    timerText.setCharacterSize(50);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition(sf::Vector2f(75, 25));

    sf::Text recipeText;
    recipeText.setFont(font);
    recipeText.setCharacterSize(16);
    recipeText.setFillColor(sf::Color::Black);

    //Window loop
    bool pedido = false;
    int bread_type = -1;
    bool bread_base = false;
    bool vendo_pedido = false;
    float layer_offset = 0;
    sf::Vector2i cursorPosition = sf::Mouse::getPosition(win);
    sf::Vector2f worldPos = win.mapPixelToCoords(cursorPosition);

    int id_escolhido;
    int camada_atual;
    int id_receita = 0;
    Ingrediente ing;
    bool ok = true;
    string prefixo_receita = "Hamburguer";
    Receita* receita;
    pilha* receita_montada;
    bool ing_picked = false;
    bool start = true;
    bool timeRunning = false;
    int score = 0;
    sf::Clock clock;
    while (win.isOpen()) {
        if (start) {
            start = false;
            id_escolhido = 0;
            camada_atual = 0;
            id_receita++;
            receita_montada = criaPilha();

            //restarts
            stringstream nomeReceita;
            nomeReceita << prefixo_receita;
            nomeReceita << " ";
            nomeReceita << id_receita;
            receita = new Receita(nomeReceita.str());
            pedido = true;
            cout << endl << "Receita a ser feita: " << (*receita).getNome() << endl << endl;
            mostra_pilha((*receita).getPilha());
        }
        
        if (id_receita >= 10) {
            ok = false;
            cout << "SCORE:" << score << "pts" << endl;
            break;
        }
        //Event Info Getting Section
        cursorPosition = sf::Mouse::getPosition(win);
        worldPos = win.mapPixelToCoords(cursorPosition);
        sf::Event e;
        float elapsed = clock.getElapsedTime().asSeconds();

        int minutes = static_cast<int>(elapsed) / 60;
        int secs = static_cast<int>(elapsed) % 60;
        int mili = static_cast<int>(elapsed) % 1000;

        stringstream ss;
        ss << minutes << ":" << secs << "   ";
        timerText.setString(ss.str());
        //cout << worldPos.x << " | " << worldPos.y << endl;
        //Event loop
        while (win.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                win.close();
            }

            if (e.type == sf::Event::KeyPressed) {
                /*if (e.key.code == sf::Keyboard::Enter) {
                    //verification
                    if (pilhas_iguais((*receita).getPilha(), receita_montada)) {
                        cout << "Parabéns! Você acertou a receita!" << endl;
                        id_receita++;
                    } else {
                        cout << "Que pena! Você errou a receita!" << endl;
                        ok = false;
                        break;
                    }

                    //resets
                    elements.clear();
                    pedido = false;
                    bread_type = -1;
                    bread_base = false;
                    layer_offset = 0.0f;
                    delete receita;
                    delete_pilha(receita_montada);

                    id_escolhido = 0;
                    camada_atual = 0;
                    id_receita++;
                    receita_montada = criaPilha();

                    //restarts
                    stringstream nome;
                    nome << prefixo_receita;
                    nome << " ";
                    nome << id_receita;
                    receita = new Receita(nome.str());
                    pedido = true;
                    cout << endl << "Receita a ser feita: " << (*receita).getNome() << endl << endl;
                    mostra_pilha((*receita).getPilha());
                }*/
            }

            if (e.type == sf::Event::MouseButtonPressed) {
                if (e.mouseButton.button == sf::Mouse::Left) {
                    if (tomate_colision.contains(worldPos)) {
                        tomate.setPosition(sf::Vector2f(430, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(tomate);
                        id_escolhido = 6;
                        ing_picked = true;
                    }

                    if (alface_colision.contains(worldPos)) {
                        alface.setPosition(sf::Vector2f(425, 495 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(alface);
                        id_escolhido = 7;
                        ing_picked = true;
                    }

                    if (bacon_colision.contains(worldPos)) {
                        bacon.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(bacon);
                        id_escolhido = 11;
                        ing_picked = true;
                    }

                    if (brioche_colision.contains(worldPos) && (bread_type == 1 | bread_type == -1)) {
                        bread_type = 1;
                        if (!bread_base) {
                            base_brioche.setPosition(sf::Vector2f(425, 500 - layer_offset));
                            elements.push_back(base_brioche);
                        } else {
                            topo_brioche.setPosition(sf::Vector2f(407, 475 - layer_offset));
                            elements.push_back(topo_brioche);
                        }
                        id_escolhido = 2;
                        ing_picked = true;
                        if (!bread_base) {
                            bread_base = true;
                        }

                        layer_offset += 6.5f;                        
                    }

                    if (cebola_car_colision.contains(worldPos)) {
                        cebola_car.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(cebola_car);
                        id_escolhido = 12;
                        ing_picked = true;
                    }

                    if (cebola_nor_colision.contains(worldPos)) {
                        cebola_nor.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(cebola_nor);
                        id_escolhido = 8;
                        ing_picked = true;
                    }

                    if (frango_colision.contains(worldPos)) {
                        frango.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(frango);
                        id_escolhido = 5;
                        ing_picked = true;
                    }

                    if (hamburguer_bov_colision.contains(worldPos)) {
                        hamburguer_bov.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(hamburguer_bov);
                        id_escolhido = 3;
                        ing_picked = true;
                    }

                    if (hamburguer_veg_colision.contains(worldPos)) {
                        hamburguer_veg.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(hamburguer_veg);
                        id_escolhido = 4;
                        ing_picked = true;
                    }

                    if (ketchup_colision.contains(worldPos)) {
                        ketchup.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(ketchup);
                        id_escolhido = 10;
                        ing_picked = true;
                    }

                    if (mustard_colision.contains(worldPos)) {
                        mustard.setPosition(sf::Vector2f(425, 500 - layer_offset));
                        layer_offset += 6.5f;
                        elements.push_back(mustard);
                        id_escolhido = 9;
                        ing_picked = true;
                    }

                    if (pao_colision.contains(worldPos) && (bread_type == 0 | bread_type == -1)) {
                        bread_type = 0;

                        if (!bread_base) {
                            base_pao.setPosition(sf::Vector2f(425, 500 - layer_offset));
                            elements.push_back(base_pao);
                        } else {
                            topo_pao.setPosition(sf::Vector2f(407, 475 - layer_offset));
                            elements.push_back(topo_pao);
                        }
                        id_escolhido = 1;
                        ing_picked = true;
                        if (!bread_base) {
                            bread_base = true;
                        }

                        layer_offset += 6.5f;
                    }

                    if (comanda_colision.contains(worldPos) && pedido) {
                        if (!vendo_pedido) {
                            stringstream rText;
                            rText << receita->getNome() << endl;
                            rText << retornaString(receita->getPilha());
                            vendo_pedido = true;
                            comanda_aberta.setPosition(sf::Vector2f(200, 300));
                            recipeText.setString(rText.str());
                            recipeText.setPosition(sf::Vector2f(220, 315));
                        } else {
                            vendo_pedido = false;
                        }
                        
                    }
                }
            }
        }

        if (ing_picked) {
            ing_picked = false;
            ing = Ingrediente(INGREDIENTES_IDS.at(id_escolhido), camada_atual, id_escolhido);
            empilha(receita_montada, ing);
            camada_atual++;
        }

        if (secs % 30 == 0 && secs != 0) {
            cout << "Timeout! (" << minutes << ":" << secs << ")\033[F" << endl;
            cout.flush();
            //verification
            if (pilhas_iguais((*receita).getPilha(), receita_montada)) {
                cout << "Parabéns! Você acertou a receita!" << endl;
                score++;
            } else {
                cout << "Que pena! Você errou a receita!" << endl;
                //ok = false;
                score--;
            }

            clock.restart();

            //resets
            elements.clear();
            pedido = false;
            bread_type = -1;
            bread_base = false;
            layer_offset = 0.0f;
            delete receita;
            delete_pilha(receita_montada);

            id_escolhido = 0;
            camada_atual = 0;
            id_receita++;
            receita_montada = criaPilha();

            //restarts
            stringstream nomeReceita;
            nomeReceita << prefixo_receita;
            nomeReceita << " ";
            nomeReceita << id_receita;
            receita = new Receita(nomeReceita.str());
            pedido = true;
            cout << endl << "Receita a ser feita: " << (*receita).getNome() << endl << endl;
            mostra_pilha((*receita).getPilha());
        }

        if (camada_atual == (*receita).getQtdIngredientes()) {
            //verification
            if (pilhas_iguais((*receita).getPilha(), receita_montada)) {
                cout << "Parabéns! Você acertou a receita!" << endl;
                score++;
            } else {
                cout << "Que pena! Você errou a receita!" << endl;
                //ok = false;
                score--;
            }

            clock.restart();

            //resets
            elements.clear();
            pedido = false;
            bread_type = -1;
            bread_base = false;
            layer_offset = 0.0f;

            delete receita;
            delete_pilha(receita_montada);
            id_escolhido = 0;
            camada_atual = 0;
            receita_montada = criaPilha();

            //restarts
            stringstream nomeReceita;
            nomeReceita << prefixo_receita;
            nomeReceita << " ";
            nomeReceita << id_receita;
            receita = new Receita(nomeReceita.str());
            pedido = true;
            cout << endl << "Receita a ser feita: " << (*receita).getNome() << endl << endl;
            mostra_pilha((*receita).getPilha());
        } 

        win.clear(sf::Color::Black);
        if (ok) {
            if (pedido) {
                win.draw(cozinha);
                if (comanda_colision.contains(worldPos)) {
                    comanda.setColor(sf::Color::Blue);
                } else {
                    comanda.setColor(originalComanda);
                }
                win.draw(comanda);

                if (vendo_pedido) {
                    win.draw(comanda_aberta);
                    win.draw(recipeText);
                }
            }
            for (sf::Sprite s : elements) {
                win.draw(s);
            }
            if (pedido && vendo_pedido) {
                win.draw(comanda_aberta);
                win.draw(recipeText);
            }
            win.draw(timerText);
        }
        
        win.display();
    }
}