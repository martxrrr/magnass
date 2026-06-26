#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <iostream>
#include <cstdint>

void  Click(sf::RenderWindow &window, const sf::Event &event){
    if(const auto* mouseClick = event.getIf<sf::Event::MouseButtonPressed>()){
        if(mouseClick->button == sf::Mouse::Button::Left){
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int mouse_x = pos.x;
            int mouse_y = pos.y;

            std::cout << "(" << mouse_x << "," << mouse_y << ")" << std::endl;

        }
    }
}

int main(){

        sf::RenderWindow window(sf::VideoMode({740, 733}), "MAGNASS", sf::Style::Titlebar | sf::Style::Close);
        window.setPosition(sf::Vector2i({400, 200}));

        sf::Texture boardTexture;
        if(!boardTexture.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/boards/chess02.jpg")){
                return -1;
        }

        sf::Sprite mainBoard(boardTexture);

        sf::RectangleShape pieceSquare(sf::Vector2f(72.f, 72.f));
        pieceSquare.setPosition({76.f, 76.f});
        pieceSquare.setOutlineColor(sf::Color::Red);
        pieceSquare.setOutlineThickness(4.f);

        
        while(window.isOpen()){
                while(const std::optional event = window.pollEvent()){
                        if(event->is<sf::Event::Closed>()){
                                window.close();
                        }
                        else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                                        window.close();
                                }
                        }
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
                                window.close();
                        }
                        Click(window, *event);
                }

                window.clear(sf::Color::Black);

                window.draw(mainBoard);
                window.draw(pieceSquare);

                window.display();
                
        }

        
        

        return 0;
}