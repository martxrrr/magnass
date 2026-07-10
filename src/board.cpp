#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <iostream>
#include <cstdint>
#include <typeinfo>
#include <initializer_list>

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

struct position{
        sf::Vector2f A1 = { 81.f, 597.f };
        sf::Vector2f A2 = { 81.f, 523.f };
        sf::Vector2f A3 = { 81.f, 450.f };
        sf::Vector2f A4 = { 81.f, 377.f };
        sf::Vector2f A5 = { 81.f, 304.f };
        sf::Vector2f A6 = { 81.f, 231.f };
        sf::Vector2f A7 = { 81.f, 153.f };
        sf::Vector2f A8 = { 81.f, 80.f  };

        sf::Vector2f B1 = { 154.f, 597.f };
        sf::Vector2f B2 = { 154.f, 523.f };
        sf::Vector2f B3 = { 154.f, 450.f };
        sf::Vector2f B4 = { 154.f, 377.f };
        sf::Vector2f B5 = { 154.f, 304.f };
        sf::Vector2f B6 = { 154.f, 231.f };
        sf::Vector2f B7 = { 154.f, 153.f };
        sf::Vector2f B8 = { 154.f, 80.f  };

        sf::Vector2f C1 = { 227.f, 597.f };
        sf::Vector2f C2 = { 227.f, 523.f };
        sf::Vector2f C3 = { 227.f, 450.f };
        sf::Vector2f C4 = { 227.f, 377.f };
        sf::Vector2f C5 = { 227.f, 304.f };
        sf::Vector2f C6 = { 227.f, 231.f };
        sf::Vector2f C7 = { 227.f, 153.f };
        sf::Vector2f C8 = { 227.f, 80.f  };

        sf::Vector2f D1 = { 300.f, 600.f };
        sf::Vector2f D2 = { 300.f, 523.f };
        sf::Vector2f D3 = { 300.f, 450.f };
        sf::Vector2f D4 = { 300.f, 377.f };
        sf::Vector2f D5 = { 300.f, 304.f };
        sf::Vector2f D6 = { 300.f, 231.f };
        sf::Vector2f D7 = { 300.f, 153.f };
        sf::Vector2f D8 = { 300.f, 80.f  };

        sf::Vector2f E1 = { 374.f, 597.f };
        sf::Vector2f E2 = { 374.f, 523.f };
        sf::Vector2f E3 = { 374.f, 450.f };
        sf::Vector2f E4 = { 374.f, 377.f };
        sf::Vector2f E5 = { 374.f, 304.f };
        sf::Vector2f E6 = { 374.f, 231.f };
        sf::Vector2f E7 = { 374.f, 153.f };
        sf::Vector2f E8 = { 374.f, 77.f  };

        sf::Vector2f F1 = { 447.f, 597.f };
        sf::Vector2f F2 = { 447.f, 523.f };
        sf::Vector2f F3 = { 447.f, 450.f };
        sf::Vector2f F4 = { 447.f, 377.f };
        sf::Vector2f F5 = { 447.f, 304.f };
        sf::Vector2f F6 = { 447.f, 231.f };
        sf::Vector2f F7 = { 447.f, 153.f };
        sf::Vector2f F8 = { 451.f, 80.f  };

        sf::Vector2f G1 = { 520.f, 597.f };
        sf::Vector2f G2 = { 520.f, 523.f };
        sf::Vector2f G3 = { 520.f, 450.f };
        sf::Vector2f G4 = { 520.f, 377.f };
        sf::Vector2f G5 = { 520.f, 304.f };
        sf::Vector2f G6 = { 520.f, 231.f };
        sf::Vector2f G7 = { 520.f, 153.f };
        sf::Vector2f G8 = { 524.f, 80.f  };

        sf::Vector2f H1 = { 593.f, 597.f };
        sf::Vector2f H2 = { 593.f, 523.f };
        sf::Vector2f H3 = { 593.f, 450.f };
        sf::Vector2f H4 = { 593.f, 377.f };
        sf::Vector2f H5 = { 593.f, 304.f };
        sf::Vector2f H6 = { 593.f, 231.f };
        sf::Vector2f H7 = { 593.f, 153.f };
        sf::Vector2f H8 = { 597.f, 80.f   };
};

class Pieces{
        public:

        void king(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture king;
                if(color == 0){
                        if(!king.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/kingB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite kingB(king);
                        sf::Vector2f pos = {374.f, 77.f};
                        kingB.setPosition(pos);

                        window.draw(kingB);
                }else if(color == 1){
                        if(!king.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/kingW.png")){
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
                        if(!queen.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/queenB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite queenB(queen);
                        queenB.setPosition({300.f, 80.f});

                        window.draw(queenB);
                }else if(color == 1){
                        if(!queen.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/queenW.png")){
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
                        if(!knight.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/knightB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite knightB(knight);
                        knightB.setPosition({524.f, 80.f});

                        window.draw(knightB);
                }else if(color == 1){
                        if(!knight.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/knightW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite knightW(knight);
                        knightW.setPosition({520.f, 597.f});

                        window.draw(knightW);
                }

        }

        void rook(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture rook;
                if(color == 0){
                        if(!rook.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/rookB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite rookB(rook);
                        rookB.setPosition({597.f, 80.f});

                        window.draw(rookB);
                }else if(color == 1){
                        if(!rook.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/rookW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite rookW(rook);
                        rookW.setPosition({593.f, 597.f});

                        window.draw(rookW);
                }

        }

        void bishop(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture bishop;
                if(color == 0){
                        if(!bishop.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/bishopB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite bishopB(bishop);
                        bishopB.setPosition({451.f, 80.f});

                        window.draw(bishopB);
                }else if(color == 1){
                        if(!bishop.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/bishopW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite bishopW(bishop);
                        bishopW.setPosition({447.f, 597.f});

                        window.draw(bishopW);
                }

        }

        void pawn(sf::RenderWindow& window, const uint8_t& color){
                sf::Texture pawn;
                if(color == 0){
                        if(!pawn.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/pawnB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite pawnB(pawn);
                        pawnB.setPosition({300.f, 153.f});

                        window.draw(pawnB);
                }else if(color == 1){
                        if(!pawn.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/pawnW.png")){
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
        if(!boardTexture.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/boards/chess02.jpg")){
                return -1;
        }

        sf::Sprite mainBoard(boardTexture);


        //highlighting the square, we use this piece of code
        sf::RectangleShape pieceSquare(sf::Vector2f(72.f, 72.f));
        pieceSquare.setFillColor(sf::Color(255, 255, 255, 0));
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

                piece.bishop(window, 0);
                piece.bishop(window, 1);

                piece.knight(window, 0);
                piece.knight(window, 1);

                piece.rook(window, 0);
                piece.rook(window, 1);

                window.draw(pieceSquare);
                

                window.display();
                
        }

        
        

        return 0;
}