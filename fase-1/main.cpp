#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <unistd.h>
#include <sstream>

#include "Receita.h"
#include "pilha.h"
#include "Ingrediente.h"
#include "constantes.h"
#include "utils.h"
#include "heap.cpp"
#include <iomanip>

#define NUM_RECEITAS_INICIAIS 10

using namespace std;

string getRecipeStr(Receita* currentRecipe) {
    stringstream rText;
    rText << currentRecipe->getNome() << endl;
    rText << retornaString(currentRecipe->getPilha());
    rText << currentRecipe->getTempoConclusao();
    rText << "s para a receita expirar...";
    return rText.str();
}

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
    comanda.setPosition(sf::Vector2f(13, 495));
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
    if (!cozinha_texture.loadFromFile("./sprites/cozinha.png")) {
        return -1;
    }

    sf::Sprite cozinha;
    cozinha.setTexture(cozinha_texture);
    cozinha.setPosition(sf::Vector2f(0, 0));
    cozinha.setScale(sf::Vector2f(0.8f, 0.9f));

    sf::Texture TitleScreen_texture;
    if (!TitleScreen_texture.loadFromFile("./sprites/TitleScreen.png")) {
        return -1;
    }

    sf::Sprite titleScreen;
    titleScreen.setTexture(TitleScreen_texture);
    titleScreen.setPosition(sf::Vector2f(0, 0));
    titleScreen.setScale(sf::Vector2f(1.5f, 1.7f));

    sf::RectangleShape startBtn;
    startBtn.setPosition(sf::Vector2f(125, 312));
    startBtn.setFillColor(sf::Color::Blue);
    startBtn.setSize(sf::Vector2f(550, 125));

    sf::RectangleShape exitBtn;
    exitBtn.setPosition(sf::Vector2f(125, 442));
    exitBtn.setFillColor(sf::Color::Blue);
    exitBtn.setSize(sf::Vector2f(550, 125));

    sf::Texture GameOverScreen_texture;
    if (!GameOverScreen_texture.loadFromFile("./sprites/GameOverScreen.png")) {
        return -1;
    }

    sf::Sprite GameOverScreen;
    GameOverScreen.setTexture(GameOverScreen_texture);
    GameOverScreen.setPosition(sf::Vector2f(0, 0));
    GameOverScreen.setScale(sf::Vector2f(0.7f, 0.8f));

    sf::RectangleShape restartBtn;
    restartBtn.setPosition(sf::Vector2f(50, 550));
    restartBtn.setFillColor(sf::Color::Blue);
    restartBtn.setSize(sf::Vector2f(400, 50));

    sf::RectangleShape mainMenuBtn;
    mainMenuBtn.setPosition(sf::Vector2f(420, 550));
    mainMenuBtn.setFillColor(sf::Color::Green);
    mainMenuBtn.setSize(sf::Vector2f(400, 50));

    sf::Texture tomate_texture;
    if (!tomate_texture.loadFromFile("./sprites/Tomate.png")) {
        return -1;
    }
    sf::Sprite tomate;
    tomate.setTexture(tomate_texture);
    tomate.setPosition(sf::Vector2f(40, 40));
    tomate.setScale(sf::Vector2f(0.25f, 0.25f));
    sf::FloatRect tomate_colision = tomate.getGlobalBounds();
    sf::Color originalTomate = tomate.getColor();
    tomate.setColor(originalTomate);

    sf::Texture alface_texture;
    if (!alface_texture.loadFromFile("./sprites/Alface.png")) {
        return -1;
    }
    sf::Sprite alface;
    alface.setTexture(alface_texture);
    alface.setPosition(sf::Vector2f(30, 190));
    alface.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect alface_colision = alface.getGlobalBounds();
    sf::Color originalAlface = alface.getColor();

    sf::Texture bacon_texture;
    if (!bacon_texture.loadFromFile("./sprites/Bacon.png")) {
        return -1;
    }
    sf::Sprite bacon;
    bacon.setTexture(bacon_texture);
    bacon.setPosition(sf::Vector2f(130, 195));
    bacon.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect bacon_colision = bacon.getGlobalBounds();
    sf::Color originalBacon = bacon.getColor();

    sf::Texture brioche_texture;
    if (!brioche_texture.loadFromFile("./sprites/Brioche.png")) {
        return -1;
    }
    sf::Sprite brioche;
    brioche.setTexture(brioche_texture);
    brioche.setPosition(sf::Vector2f(430, 233));
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
    cebola_car.setPosition(sf::Vector2f(40, 115));
    cebola_car.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect cebola_car_colision = cebola_car.getGlobalBounds();
    sf::Color originalCebola_Car = cebola_car.getColor();

    sf::Texture cebola_nor_texture;
    if (!cebola_nor_texture.loadFromFile("./sprites/Cebola_Nor.png")) {
        return -1;
    }
    sf::Sprite cebola_nor;
    cebola_nor.setTexture(cebola_nor_texture);
    cebola_nor.setPosition(sf::Vector2f(130, 115));
    cebola_nor.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect cebola_nor_colision = cebola_nor.getGlobalBounds();
    sf::Color originalCebola_Nor = cebola_nor.getColor();

    sf::Texture frango_texture;
    if (!frango_texture.loadFromFile("./sprites/Frango.png")) {
        return -1;
    }
    sf::Sprite frango;
    frango.setTexture(frango_texture);
    frango.setPosition(sf::Vector2f(30, 280));
    frango.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect frango_colision = frango.getGlobalBounds();
    sf::Color originalFrango = frango.getColor();

    sf::Texture hamburguer_bov_texture;
    if (!hamburguer_bov_texture.loadFromFile("./sprites/Hamburguer_Bov.png")) {
        return -1;
    }
    sf::Sprite hamburguer_bov;
    hamburguer_bov.setTexture(hamburguer_bov_texture);
    hamburguer_bov.setPosition(sf::Vector2f(130, 280));
    hamburguer_bov.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect hamburguer_bov_colision = hamburguer_bov.getGlobalBounds();
    sf::Color originalHamburguer_Bov = hamburguer_bov.getColor();

    sf::Texture hamburguer_veg_texture;
    if (!hamburguer_veg_texture.loadFromFile("./sprites/Hamburguer_Veg.png")) {
        return -1;
    }
    sf::Sprite hamburguer_veg;
    hamburguer_veg.setTexture(hamburguer_veg_texture);
    hamburguer_veg.setPosition(sf::Vector2f(130, 365));
    hamburguer_veg.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect hamburguer_veg_colision = hamburguer_veg.getGlobalBounds();
    sf::Color originalHamburguer_Veg = hamburguer_veg.getColor();

    sf::Texture ketchup_texture;
    if (!ketchup_texture.loadFromFile("./sprites/Ketchup.png")) {
        return -1;
    }
    sf::Sprite ketchup;
    ketchup.setTexture(ketchup_texture);
    ketchup.setPosition(sf::Vector2f(350, 210));
    ketchup.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect ketchup_colision = ketchup.getGlobalBounds();
    sf::Color originalKetchup = ketchup.getColor();

    sf::Texture ketchup_sauce_texture;
    if (!ketchup_sauce_texture.loadFromFile("./sprites/ketchup_sauce.png")) {
        return -1;
    }
    sf::Sprite ketchup_sauce;
    ketchup_sauce.setTexture(ketchup_sauce_texture);
    ketchup_sauce.setPosition(sf::Vector2f(310, 290));
    ketchup_sauce.setScale(sf::Vector2f(0.25f, 0.25f));
    sf::FloatRect ketchup_sauce_colision = ketchup_sauce.getGlobalBounds();
    sf::Color originalKetchupSauce = ketchup_sauce.getColor();

    sf::Texture mustard_texture;
    if (!mustard_texture.loadFromFile("./sprites/Mustard.png")) {
        return -1;
    }
    sf::Sprite mustard;
    mustard.setTexture(mustard_texture);
    mustard.setPosition(sf::Vector2f(270, 215));
    mustard.setScale(sf::Vector2f(0.3f, 0.3f));
    sf::FloatRect mustard_colision = mustard.getGlobalBounds();
    sf::Color originalMustard = mustard.getColor();

    sf::Texture mustard_sauce_texture;
    if (!mustard_sauce_texture.loadFromFile("./sprites/mustard_sauce.png")) {
        return -1;
    }
    sf::Sprite mustard_sauce;
    mustard_sauce.setTexture(mustard_sauce_texture);
    mustard_sauce.setPosition(sf::Vector2f(420, 290));
    mustard_sauce.setScale(sf::Vector2f(0.25f, 0.25f));
    sf::FloatRect mustard_sauce_colision = mustard_sauce.getGlobalBounds();
    sf::Color originalMustardSauce = mustard_sauce.getColor();

    sf::Texture pao_texture;
    if (!pao_texture.loadFromFile("./sprites/Pao.png")) {
        return -1;
    }
    sf::Sprite pao;
    pao.setTexture(pao_texture);
    pao.setPosition(sf::Vector2f(500, 230));
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

    sf::Font pixelate;
    pixelate.loadFromFile("./assets/pixelate.ttf");

    sf::Font handmade;
    handmade.loadFromFile("./assets/handmade.ttf");


    sf::Text timerText;
    timerText.setFont(pixelate);
    timerText.setCharacterSize(20);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition(sf::Vector2f(420, 150));

    sf::Text recipeText;
    recipeText.setFont(handmade);
    recipeText.setCharacterSize(16);
    recipeText.setFillColor(sf::Color::Black);

    sf::Text remainingRecipesText;
    remainingRecipesText.setFont(pixelate);
    remainingRecipesText.setCharacterSize(12);
    remainingRecipesText.setFillColor(sf::Color::Black);
    remainingRecipesText.setPosition(sf::Vector2f(340, 180));

    sf::Text titleText;
    titleText.setFont(font);
    titleText.setCharacterSize(16);
    titleText.setFillColor(sf::Color::Black);

    sf::Text GameOverText;
    GameOverText.setFont(font);
    GameOverText.setCharacterSize(16);
    GameOverText.setFillColor(sf::Color::Black);

    sf::Text GameOverTitle;
    GameOverTitle.setFont(pixelate);
    GameOverTitle.setCharacterSize(24);
    GameOverTitle.setFillColor(sf::Color::Black);

    sf::Text StartingScreenText;
    StartingScreenText.setFont(font);
    StartingScreenText.setCharacterSize(24);
    StartingScreenText.setFillColor(sf::Color::White);

    sf::Cursor cursorMao;
    if (!cursorMao.loadFromSystem(sf::Cursor::Hand)) {
        return -1;
    }

    sf::Cursor cursorSeta;
    if (!cursorSeta.loadFromSystem(sf::Cursor::Arrow)) {
        return -1;
    }

    // 1. Música de Fundo (sf::Music)
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile("./assets/audio/musica_fundo.ogg")) {
        std::cerr << "ERRO: Falha ao carregar musica_fundo.ogg" << std::endl;
        // O jogo pode continuar sem música, mas o ideal é verificar a pasta.
    } else {
        backgroundMusic.setLoop(true); // Toca em loop
        backgroundMusic.setVolume(50.f); // Volume ajustado para 50%
    }
    
    // 2. Buffer para Efeito Sonoro de Pegar Item (sf::Sound)
    sf::SoundBuffer hoverSoundBuffer;
    if (!hoverSoundBuffer.loadFromFile("./assets/audio/hover_item.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound hoverSound;
    hoverSound.setBuffer(hoverSoundBuffer);

    sf::SoundBuffer alfaceSoundBuffer;
    if (!alfaceSoundBuffer.loadFromFile("./assets/audio/alface.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound alfaceSound;
    alfaceSound.setBuffer(alfaceSoundBuffer);

    sf::SoundBuffer clockSoundBuffer;
    if (!clockSoundBuffer.loadFromFile("./assets/audio/clock.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound clockSound;
    clockSound.setBuffer(clockSoundBuffer);
    clockSound.setLoop(true);

    sf::SoundBuffer cuttingSoundBuffer;
    if (!cuttingSoundBuffer.loadFromFile("./assets/audio/cutting.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound cuttingSound;
    cuttingSound.setBuffer(cuttingSoundBuffer);

    sf::SoundBuffer expiredSoundBuffer;
    if (!expiredSoundBuffer.loadFromFile("./assets/audio/expired.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound expiredSound;
    expiredSound.setBuffer(expiredSoundBuffer);

    sf::SoundBuffer failureSoundBuffer;
    if (!failureSoundBuffer.loadFromFile("./assets/audio/failure.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound failureSound;
    failureSound.setBuffer(failureSoundBuffer);

    sf::SoundBuffer fryingSoundBuffer;
    if (!fryingSoundBuffer.loadFromFile("./assets/audio/frying.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound fryingSound;
    fryingSound.setBuffer(fryingSoundBuffer);

    sf::SoundBuffer saucesSoundBuffer;
    if (!saucesSoundBuffer.loadFromFile("./assets/audio/sauces.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound saucesSound;
    saucesSound.setBuffer(saucesSoundBuffer);

    sf::SoundBuffer successSoundBuffer;
    if (!successSoundBuffer.loadFromFile("./assets/audio/success.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound successSound;
    successSound.setBuffer(successSoundBuffer);

    sf::SoundBuffer tomato_cutSoundBuffer;
    if (!tomato_cutSoundBuffer.loadFromFile("./assets/audio/tomato_cut.wav")) {
        std::cerr << "ERRO: Falha ao carregar hover_item.wav" << std::endl;
    }
    sf::Sound tomato_cutSound;
    tomato_cutSound.setBuffer(tomato_cutSoundBuffer);
    


    backgroundMusic.play();

    //Window loop
    bool pedido = false;
    int bread_type = -1;
    bool bread_base = false;
    bool vendo_pedido = false;
    float layer_offset = 0;
    sf::Vector2i cursorPosition = sf::Mouse::getPosition(win);
    sf::Vector2f worldPos = win.mapPixelToCoords(cursorPosition);

    HeapPrioridade fila_de_receitas;
    int id_escolhido;
    int camada_atual;
    int id_receita = 0;
    Ingrediente ing;
    bool playing = true;
    bool onMenu = true;
    string prefixo_receita = "Hamburguer";
    Receita* currentRecipe;
    int currentRecipeId = 0;
    pilha* receita_montada;
    bool ing_picked = false;
    bool start = true;
    bool timeRunning = false;
    bool fTimeSet = false;
    bool exit = false;
    int score = 9;
    sf::Clock clock;
    sf::Event e;
    float Felapsed;
    int Fminutes, Fsecs, Fmili;
    while (win.isOpen() && !exit) {
        while (onMenu) {
            cursorPosition = sf::Mouse::getPosition(win);
            worldPos = win.mapPixelToCoords(cursorPosition);

            while (win.pollEvent(e)) {
                if (e.type == sf::Event::Closed) {
                    win.close();
                }

                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        if (startBtn.getGlobalBounds().contains(worldPos)) {
                            playing = true;
                            start = true;
                            onMenu = false;
                        }

                        if (exitBtn.getGlobalBounds().contains(worldPos)) {
                            win.close();
                            exit = true;
                            break;
                        }
                        hoverSound.play();
                    }
                }
            }
            win.clear(sf::Color::Black);
            win.draw(titleScreen);
            //win.draw(startBtn);
            //win.draw(exitBtn);
            win.display();
        }

        while (!onMenu) {
            if (start) {
                score = 9;
                fila_de_receitas.clear();
                start = false;
                id_escolhido = 0;
                camada_atual = 0;
                id_receita++;
                elements.clear();
                delete_pilha(receita_montada);
                receita_montada = criaPilha();

                //restarts
                // Inicializa o Heap com 10 receitas
                for (int i = 0; i < NUM_RECEITAS_INICIAIS; ++i) {
                    string nome = "Pedido #" + to_string(i + 1);
                    fila_de_receitas.inserir(new Receita(nome));
                }
                fila_de_receitas.rebalancear();
                pedido = true;
                currentRecipe = fila_de_receitas.getElementos()[0];
                /*for (Receita* r : fila_de_receitas.getElementos()) {
                    cout << endl << "Receita a ser feita: " << (*r).getNome() << endl << endl;
                    mostra_pilha((*r).getPilha());
                    cout << endl << "EM: " << r->getTempoConclusao() << " segundos!" << endl;
                }*/
                //cout << endl << "Receita a ser feita: " << (*receita).getNome() << endl << endl;
                //mostra_pilha((*receita).getPilha());
            }
            //Event Info Getting Section
            cursorPosition = sf::Mouse::getPosition(win);
            worldPos = win.mapPixelToCoords(cursorPosition);

            if (playing) {
                float elapsed;
                float old = elapsed;
                elapsed = clock.getElapsedTime().asSeconds();

                int minutes = static_cast<int>(elapsed) / 60;
                int secs = static_cast<int>(elapsed) % 60;
                int mili = static_cast<int>(elapsed) % 1000;

                stringstream ttext;
                ttext << setfill('0') << setw(2) << minutes << ":"
                    << setfill('0') << setw(2) << secs;

                timerText.setString(ttext.str());

                int oldminutes = static_cast<int>(old) / 60;
                int oldsecs = static_cast<int>(old) % 60;
                int oldmili = static_cast<int>(old) % 1000;

                stringstream rmRecText;
                rmRecText << "Remaining Recipes: " << setfill('0') << setw(2) << fila_de_receitas.getSize();
                remainingRecipesText.setString(rmRecText.str());
                while (win.pollEvent(e)) {
                    if (e.type == sf::Event::Closed) {
                        win.close();
                    }

                    if (e.type == sf::Event::KeyPressed) {
                        if (e.key.code == sf::Keyboard::Right && !fila_de_receitas.estaVazio()) {
                            if (currentRecipeId < fila_de_receitas.getSize() - 1) {
                                currentRecipeId++;
                            } else {
                                currentRecipeId = 0;
                            }
                            bread_type = -1;
                            bread_base = false;
                            currentRecipe = fila_de_receitas.getElementos()[currentRecipeId];
                            delete_pilha(receita_montada);
                            elements.clear();
                            receita_montada = criaPilha();
                        }

                        if (e.key.code == sf::Keyboard::Left && !fila_de_receitas.estaVazio()) {
                            if (currentRecipeId > 0) {
                                currentRecipeId--;
                            } else {
                                currentRecipeId = fila_de_receitas.getSize() - 1;
                            }
                            bread_type = -1;
                            bread_base = false;
                            currentRecipe = fila_de_receitas.getElementos()[currentRecipeId];
                            delete_pilha(receita_montada);
                            elements.clear();
                            receita_montada = criaPilha();
                        }
                    }

                    if (e.type == sf::Event::MouseButtonPressed) {
                        if (e.mouseButton.button == sf::Mouse::Left) {
                            if (tomate_colision.contains(worldPos)) {
                                tomate.setPosition(sf::Vector2f(430, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(tomate);
                                id_escolhido = 6;
                                ing_picked = true;
                                tomato_cutSound.play();
                            }

                            if (alface_colision.contains(worldPos)) {
                                alface.setPosition(sf::Vector2f(425, 345 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(alface);
                                id_escolhido = 7;
                                ing_picked = true;
                                alfaceSound.play();
                            }

                            if (bacon_colision.contains(worldPos)) {
                                bacon.setPosition(sf::Vector2f(425, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(bacon);
                                id_escolhido = 11;
                                ing_picked = true;
                                fryingSound.play();
                            }

                            if (brioche_colision.contains(worldPos) && (bread_type == 1 | bread_type == -1)) {
                                bread_type = 1;
                                if (!bread_base) {
                                    base_brioche.setPosition(sf::Vector2f(425, 350 - layer_offset));
                                    elements.push_back(base_brioche);
                                } else {
                                    topo_brioche.setPosition(sf::Vector2f(407, 335 - layer_offset));
                                    elements.push_back(topo_brioche);
                                }
                                id_escolhido = 2;
                                ing_picked = true;
                                if (!bread_base) {
                                    bread_base = true;
                                }

                                layer_offset += 6.5f;
                                cuttingSound.play();                        
                            }

                            if (cebola_car_colision.contains(worldPos)) {
                                cebola_car.setPosition(sf::Vector2f(425, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(cebola_car);
                                id_escolhido = 12;
                                ing_picked = true;
                                fryingSound.play();
                            }

                            if (cebola_nor_colision.contains(worldPos)) {
                                cebola_nor.setPosition(sf::Vector2f(425, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(cebola_nor);
                                id_escolhido = 8;
                                ing_picked = true;
                                tomato_cutSound.play();
                            }

                            if (frango_colision.contains(worldPos)) {
                                frango.setPosition(sf::Vector2f(425, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(frango);
                                id_escolhido = 5;
                                ing_picked = true;
                                fryingSound.play();
                            }

                            if (hamburguer_bov_colision.contains(worldPos)) {
                                hamburguer_bov.setPosition(sf::Vector2f(425, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(hamburguer_bov);
                                id_escolhido = 3;
                                ing_picked = true;
                                fryingSound.play();
                            }

                            if (hamburguer_veg_colision.contains(worldPos)) {
                                hamburguer_veg.setPosition(sf::Vector2f(425, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(hamburguer_veg);
                                id_escolhido = 4;
                                ing_picked = true;
                                fryingSound.play();
                            }

                            if (ketchup_colision.contains(worldPos)) {
                                ketchup_sauce.setPosition(sf::Vector2f(430, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(ketchup_sauce);
                                id_escolhido = 10;
                                ing_picked = true;
                                saucesSound.play();
                            }

                            if (mustard_colision.contains(worldPos)) {
                                mustard_sauce.setPosition(sf::Vector2f(430, 350 - layer_offset));
                                layer_offset += 6.5f;
                                elements.push_back(mustard_sauce);
                                id_escolhido = 9;
                                ing_picked = true;
                                saucesSound.play();
                            }

                            if (pao_colision.contains(worldPos) && (bread_type == 0 | bread_type == -1)) {
                                bread_type = 0;

                                if (!bread_base) {
                                    base_pao.setPosition(sf::Vector2f(425, 350 - layer_offset));
                                    elements.push_back(base_pao);
                                } else {
                                    topo_pao.setPosition(sf::Vector2f(407, 335 - layer_offset));
                                    elements.push_back(topo_pao);
                                }
                                id_escolhido = 1;
                                ing_picked = true;
                                if (!bread_base) {
                                    bread_base = true;
                                }

                                layer_offset += 6.5f;
                                cuttingSound.play();
                            }

                            if (comanda_colision.contains(worldPos) && pedido) {
                                if (!vendo_pedido) {
                                    
                                    vendo_pedido = true;
                                    sf::Vector2f cmd_pos = comanda.getPosition();
                                    comanda_aberta.setPosition(sf::Vector2f(cmd_pos.x + 550, cmd_pos.y - 135));
                                    recipeText.setPosition(sf::Vector2f(cmd_pos.x + 565, cmd_pos.y - 125));
                                } else {
                                    vendo_pedido = false;
                                }
                                expiredSound.play();
                            }
                        }
                    }
                }

                for (Receita* r : fila_de_receitas.getElementos()) {
                    if (secs < oldsecs) {
                        oldsecs = secs;
                    }
                    r->decrementarTempo((secs - oldsecs)); 
                }

                fila_de_receitas.rebalancear();

                // C. Checar e remover receitas prontas (Regra: a cada receita pronta)
                while (!fila_de_receitas.estaVazio() && fila_de_receitas.olharMinimo()->expirou()) {
                    
                    Receita* pronta = fila_de_receitas.extrairMinimo();
                    // Libera a memória da receita pronta

                    cout << "Timeout! (" << minutes << ":" << secs << ")\033[F" << endl;
                    expiredSound.play();
                    cout.flush();
                    //verification
                    if (pilhas_iguais((*pronta).getPilha(), receita_montada)) {
                        cout << "Parabéns! Você acertou a " << pronta->getNome() << "em cima do tempo!" << endl;
                        successSound.play();
                        if (currentRecipe->getId() == pronta->getId()) {
                            delete_pilha(receita_montada);
                            elements.clear();
                        }
                    } else {
                        cout << "Que pena! A receita: " << pronta->getNome() << "expirou" << endl;
                        //playing = false;
                        score--;
                        failureSound.play();
                    }
                    
                    int rId = 0;
                    if (!fila_de_receitas.estaVazio()) {
                        cout << "inside while loop" << endl;
                        for (Receita* r : fila_de_receitas.getElementos()) {
                            cout <<  rId << ". " << r->getNome() << " | " << r->getId() << endl;
                            rId++;
                        }
                    } else {
                        playing = false;
                        break;
                    }
                    
                    //clock.restart();
                    //vendo_pedido = false;
                    //resets
                    
                    //fila_de_receitas.deletar(0);
                    fila_de_receitas.rebalancear();
                    if (currentRecipe->getId() == pronta->getId()) {
                        cout << currentRecipe->getId() << " " << pronta->getId() << endl;
                        currentRecipe = fila_de_receitas.getElementos()[0];
                        currentRecipeId = 0;
                        pedido = false;
                        bread_type = -1;
                        bread_base = false;
                        layer_offset = 0.0f;
                        id_escolhido = 0;
                        camada_atual = 0;
                        id_receita++;
                        receita_montada = criaPilha();
                    }
                    delete pronta; 
                    currentRecipeId == fila_de_receitas.find(currentRecipe->getId());
                    if (fila_de_receitas.getSize() == 1) {
                        clockSound.play();
                    }

                    //restarts
                    pedido = true;
                }

                if (fila_de_receitas.estaVazio()) {
                    playing = false;
                }
                

                if (ing_picked) {
                    ing_picked = false;
                    ing = Ingrediente(INGREDIENTES_IDS.at(id_escolhido), camada_atual, id_escolhido);
                    empilha(receita_montada, ing);
                    camada_atual++;
                }

                if (alface_colision.contains(worldPos) || bacon_colision.contains(worldPos) || brioche_colision.contains(worldPos)
                    || pao_colision.contains(worldPos) || cebola_car_colision.contains(worldPos) || cebola_nor_colision.contains(worldPos)
                    || comanda_colision.contains(worldPos) || frango_colision.contains(worldPos) || hamburguer_bov_colision.contains(worldPos)
                    || hamburguer_veg_colision.contains(worldPos) || ketchup_colision.contains(worldPos) || mustard_colision.contains(worldPos)
                    || tomate_colision.contains(worldPos)) {
                    win.setMouseCursor(cursorMao);
                } else {
                    win.setMouseCursor(cursorSeta);
                }        

                if (camada_atual == (*currentRecipe).getQtdIngredientes()) {
                    //verification
                    if (pilhas_iguais((*currentRecipe).getPilha(), receita_montada)) {
                        cout << "Parabéns! Você acertou a receita: " << currentRecipe->getNome() << endl;
                        successSound.play();
                    } else {
                        cout << "Que pena! Você errou a receita!" << endl;
                        score--;
                        failureSound.play();
                    }

                    int rId = 0;
                    cout << "Inside verification clause" << endl;
                    for (Receita* r : fila_de_receitas.getElementos()) {
                        cout <<  rId << ". " << r->getNome() << endl;
                        rId++;
                    }

                    fila_de_receitas.deletar(currentRecipeId);
                    if (fila_de_receitas.getSize() == 1) {
                        clockSound.play();
                    }
                    if (fila_de_receitas.estaVazio()) {
                        playing = false;
                        continue;
                    }

                    fila_de_receitas.rebalancear();
                    currentRecipe = fila_de_receitas.getElementos()[0];
                    //resets
                    elements.clear();
                    pedido = false;
                    bread_type = -1;
                    bread_base = false;
                    layer_offset = 0.0f;

                    //delete currentRecipe;
                    delete_pilha(receita_montada);
                    id_escolhido = 0;
                    camada_atual = 0;
                    receita_montada = criaPilha();

                    //restarts
                    pedido = true;
                } 

                win.clear(sf::Color::Black);
                if (pedido) {
                    win.draw(cozinha);
                    if (comanda_colision.contains(worldPos)) {
                        comanda.setColor(sf::Color::Blue);
                    } else {
                        comanda.setColor(originalComanda);
                    }
                    win.draw(comanda);
                    if (vendo_pedido) {
                        string recText = getRecipeStr(currentRecipe);
                        recipeText.setString(sf::String::fromUtf8(recText.begin(), recText.end()));
                        win.draw(comanda_aberta);
                        win.draw(recipeText);
                    }
                }

                for (sf::Sprite s : elements) {
                    win.draw(s);
                }

                if (pedido && vendo_pedido) {
                    string recText = getRecipeStr(currentRecipe);
                    recipeText.setString(sf::String::fromUtf8(recText.begin(), recText.end()));
                    win.draw(comanda_aberta);
                    win.draw(recipeText);
                }
                win.draw(timerText);
                win.draw(remainingRecipesText);
            } else {
                if (score <= 5) {
                    failureSound.play();
                } else {
                    successSound.play();
                }
                clockSound.stop();
                while (win.pollEvent(e)) {
                    if (e.type == sf::Event::Closed) {
                        win.close();
                    }

                    if (e.type == sf::Event::MouseButtonPressed) {
                        if (e.mouseButton.button == sf::Mouse::Left) {
                            if (restartBtn.getGlobalBounds().contains(worldPos)) {
                                playing = true;
                                start = true;
                            }

                            if (mainMenuBtn.getGlobalBounds().contains(worldPos)) {
                                playing = false;
                                start = false;
                                onMenu = true;
                            }
                            hoverSound.play();
                        }
                    }
                }
                win.clear(sf::Color::Black);
                if (!fTimeSet) {
                    Felapsed = clock.getElapsedTime().asSeconds();

                    Fminutes = static_cast<int>(Felapsed) / 60;
                    Fsecs = static_cast<int>(Felapsed) % 60;
                    fTimeSet = true;
                }

                clock.restart();
                string status;
                if (score < 0) {
                    status = "Oh my god... What have you done?!";
                } else if (score == 0) {
                    status = "Are you kidding with me?";
                } else if (score == 1) {
                    status = "Almost there mate... Just 9 points behind.";
                } else if (score < 5) {
                    status = "It's decent.";
                } else if (score == 5) {
                    status = "Half way to the glory!";
                } else if (score < 7) {
                    status = "At least you passed the grade...";
                } else if (score == 8) {
                    status = "Now, in fact you was almost there!";
                } else if (score == 9) {
                    status = "Really nice Chef!";
                } else {
                    status = "Are you a God or Something?";
                }
                
                stringstream gmOvrStrS;
                gmOvrStrS << "\n\"" << status << "\"\nTime Elapsed: "
                        << setfill('.') << setw(36) << "" << setfill('0') << setw(2) 
                        << Fminutes << ":" << setfill('0') << setw(2) << Fsecs << "\nScore: "
                        << setfill('.') << setw(48) << score << "pts\n" << "Press R to restart or Press Q to go to Main Menu!";

                string gameOverString = gmOvrStrS.str();

                GameOverText.setString(sf::String::fromUtf8(gameOverString.begin(), gameOverString.end()));
                GameOverText.setPosition(sf::Vector2f(175, 390));
                GameOverTitle.setString("Game Over!");
                GameOverTitle.setPosition(sf::Vector2f(275, 350));
                win.draw(GameOverScreen);
                //win.draw(restartBtn);
                //win.draw(mainMenuBtn);
                win.draw(GameOverText);
                win.draw(GameOverTitle);
                //break;
            }
            win.display();
        }
    }

    if (backgroundMusic.getStatus() == sf::Music::Playing || backgroundMusic.getStatus() == sf::Music::Paused) {
        backgroundMusic.stop(); // Garante que o thread de áudio seja interrompido
    }

    cout << "Out of the windowloop" << endl;
    free(currentRecipe);
    free(receita_montada);
}
