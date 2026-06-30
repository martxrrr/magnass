#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <iostream>
#include <cstdint>
#include <typeinfo>

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

class Pieces{
        public:

        void king(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture king;
                if(color == 0){
                        if(!king.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/black_pieces/kingB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite kingB(king);
                        kingB.setPosition({374.f, 77.f});

                        window.draw(kingB);
                }else if(color == 1){
                        if(!king.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/white_pieces/kingW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite kingW(king);
                        kingW.setPosition({374.f, 597.f});

                        window.draw(kingW);
                }

        }

        void queen(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture queen;
                if(color == 0){
                        if(!queen.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/black_pieces/queenB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite queenB(queen);
                        queenB.setPosition({300.f, 80.f});

                        window.draw(queenB);
                }else if(color == 1){
                        if(!queen.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/white_pieces/queenW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite queenW(queen);
                        queenW.setPosition({300.f, 600.f});

                        window.draw(queenW);
                }

        }

        void knight(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture knight;
                if(color == 0){
                        if(!knight.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/black_pieces/knightB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite knightB(knight);
                        knightB.setPosition({300.f, 80.f});

                        window.draw(knightB);
                }else if(color == 1){
                        if(!knight.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/white_pieces/knightW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite knightW(knight);
                        knightW.setPosition({300.f, 600.f});

                        window.draw(knightW);
                }

        }

        void rook(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture rook;
                if(color == 0){
                        if(!rook.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/black_pieces/rookB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite rookB(rook);
                        rookB.setPosition({300.f, 80.f});

                        window.draw(rookB);
                }else if(color == 1){
                        if(!rook.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/white_pieces/rookW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite rookW(rook);
                        rookW.setPosition({300.f, 600.f});

                        window.draw(rookW);
                }

        }

        void bishop(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture bishop;
                if(color == 0){
                        if(!bishop.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/black_pieces/bishopB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite bishopB(bishop);
                        bishopB.setPosition({300.f, 80.f});

                        window.draw(bishopB);
                }else if(color == 1){
                        if(!bishop.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/white_pieces/bishopW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite bishopW(bishop);
                        bishopW.setPosition({300.f, 600.f});

                        window.draw(bishopW);
                }

        }

        void pawn(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture pawn;
                if(color == 0){
                        if(!pawn.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/black_pieces/pawnB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite pawnB(pawn);
                        pawnB.setPosition({300.f, 153.f});

                        window.draw(pawnB);
                }else if(color == 1){
                        if(!pawn.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/white_pieces/pawnW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite pawnW(pawn);
                        pawnW.setPosition({300.f, 523.f});

                        window.draw(pawnW);
                }

        }
        
};

int main(){

        sf::RenderWindow window(sf::VideoMode({740, 733}), "MAGNASS", sf::Style::Titlebar | sf::Style::Close);
        window.setPosition(sf::Vector2i({400, 200}));

        sf::Texture boardTexture;
        if(!boardTexture.loadFromFile("/home/martxrrr/Programming/MAIN/C++/magnass/assets/boards/chess02.jpg")){
                return -1;
        }

        sf::Sprite mainBoard(boardTexture);


        //highlighting the square, we use this piece of code
        sf::RectangleShape pieceSquare(sf::Vector2f(72.f, 72.f));
        pieceSquare.setPosition({297.f, 77.f}); //the difference will always be the starting point where to draw the square
        pieceSquare.setOutlineColor(sf::Color::Red);
        pieceSquare.setOutlineThickness(4.f);

        Pieces piece;


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

                piece.king(window, 0);
                piece.king(window, 1);

                piece.queen(window, 0);
                piece.queen(window, 1);

                piece.pawn(window, 0);
                piece.pawn(window, 1);

                window.draw(pieceSquare);
                

                window.display();
                
        }

        
        

        return 0;
}