#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <iostream>
#include <cstdint>
#include <typeinfo>



struct Positions{
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
        sf::Vector2f H8 = { 597.f, 80.f  };
};


void getSquare(sf::RenderWindow &window, const sf::Event &event){
        Positions position;
        const std::vector<sf::Vector2f> positions = {   
                                                           position.A1, position.A2, position.A3, position.A4,
                                                           position.A5, position.A6, position.A7, position.A8,
                                                           position.B1, position.B2, position.B3, position.B4,
                                                           position.B5, position.B6, position.B7, position.B8,
                                                           position.C1, position.C2, position.C3, position.C4,
                                                           position.C5, position.C6, position.C7, position.C8,
                                                           position.D1, position.D2, position.D3, position.D4,
                                                           position.D5, position.D6, position.D7, position.D8,
                                                           position.E1, position.E2, position.E3, position.E4,
                                                           position.E5, position.E6, position.E7, position.E8,
                                                           position.F1, position.F2, position.F3, position.F4,
                                                           position.F5, position.F6, position.F7, position.F8,
                                                           position.G1, position.G2, position.G3, position.G4,
                                                           position.G5, position.G6, position.G7, position.G8,
                                                           position.H1, position.H2, position.H3, position.H4,
                                                           position.H5, position.H6, position.H7, position.H8,
                                                    };
        
        sf::Vector2f clickPosition;
        if(const auto* mouseClick = event.getIf<sf::Event::MouseButtonPressed>()){
                if(mouseClick->button == sf::Mouse::Button::Left){
                        sf::Vector2i pos = sf::Mouse::getPosition(window);
                        float mouseX = static_cast<float>(pos.x);
                        float mouseY = static_cast<float>(pos.y);

                        sf::Vector2f click_position = {mouseX, mouseY};
                        clickPosition = click_position;
                }
        }
        float diffX{};
        float diffY{};

        std::array<double, 4> euclideans;
        sf::Vector2f closest = { };
  
        for(auto position{ 0 }; position < 4; position++){
                diffX = pow((positions[position].x - clickPosition.x), 2);
                diffY = pow((positions[position].y - clickPosition.y), 2);
                double sum { diffX + diffY };

                double euclidean { sqrt(sum) };
                euclideans[position] = euclidean;

                std::cout << "(" << diffX << " , " <<  diffY << ")\n"; //  << " mean: " << euclidean << "\n";
        }

        double close { };
        {
                std::array<double, 4> virtualEuclideans;
                virtualEuclideans = euclideans;
                
                for(auto i { 1 }; i < virtualEuclideans.size(); i++){
                        for(auto j { 0 }; j < virtualEuclideans.size() - 1; j++){
                                if(virtualEuclideans[j] > virtualEuclideans[j + 1]){
                                        double temp = virtualEuclideans[j + 1];
                                        virtualEuclideans[j + 1] = virtualEuclideans[j];
                                        virtualEuclideans[j] = temp;
                                }
                        }
                }
                for(auto k { 0 }; k < virtualEuclideans.size(); k++){
                        std::cout << virtualEuclideans[k] << "\n";
                }

                std::cout << std::endl;
                for(auto l { 0 }; l < euclideans.size(); l++){
                        std::cout << euclideans[l] << "\n";
                }

                close = virtualEuclideans[0];
        }

        int index;

        for(int j { 0 }; j < euclideans.size(); j++){
                int idx;
                if(euclideans[j] == close){
                        idx = j;
                        // std::cout << "Found it at index: " << idx << "\n";
                }else{
                        continue;
                }
        index = idx;
        }
        std::cout << std::endl;
        closest = {positions[index].x, positions[index].y};

        std::cout << "(" << closest.x << ", " << closest.y << ")" << "\n";
}

class Pieces{
        public:

        void king(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
                sf::Texture king;
                if(color == 0){
                        if(!king.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/kingB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite kingB(king);
                        kingB.setPosition({position});

                        window.draw(kingB);
                }else if(color == 1){
                        if(!king.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/kingW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite kingW(king);
                        kingW.setPosition({position});

                        window.draw(kingW);
                }

        }

        void queen(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
                sf::Texture queen;
                if(color == 0){
                        if(!queen.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/queenB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite queenB(queen);
                        queenB.setPosition({position});

                        window.draw(queenB);
                }else if(color == 1){
                        if(!queen.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/queenW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite queenW(queen);
                        queenW.setPosition({position});

                        window.draw(queenW);
                }

        }

        void knight(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
                sf::Texture knight;
                if(color == 0){
                        if(!knight.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/knightB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite knightB(knight);
                        knightB.setPosition({position});

                        window.draw(knightB);
                }else if(color == 1){
                        if(!knight.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/knightW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite knightW(knight);
                        knightW.setPosition({position});

                        window.draw(knightW);
                }

        }

        void rook(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
                sf::Texture rook;
                if(color == 0){
                        if(!rook.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/rookB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite rookB(rook);
                        rookB.setPosition({position});

                        window.draw(rookB);
                }else if(color == 1){
                        if(!rook.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/rookW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite rookW(rook);
                        rookW.setPosition({position});

                        window.draw(rookW);
                }

        }

        void bishop(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
                sf::Texture bishop;
                if(color == 0){
                        if(!bishop.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/bishopB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite bishopB(bishop);
                        bishopB.setPosition({position});

                        window.draw(bishopB);
                }else if(color == 1){
                        if(!bishop.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/bishopW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite bishopW(bishop);
                        bishopW.setPosition({position});

                        window.draw(bishopW);
                }

        }

        void pawn(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
                sf::Texture pawn;
                if(color == 0){
                        if(!pawn.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/pawnB.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite pawnB(pawn);
                        pawnB.setPosition({position});

                        window.draw(pawnB);
                }else if(color == 1){
                        if(!pawn.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/pawnW.png")){
                                std::cout << "Error loading the image file! " << "\n";
                        }
                        sf::Sprite pawnW(pawn);
                        pawnW.setPosition({position});

                        window.draw(pawnW);
                }

        }
        
};

int main(){

        constexpr int width { 740 };
        constexpr int height { 733 };

        constexpr int x { 500 };
        constexpr int y { 50 };

        sf::RenderWindow window(sf::VideoMode({width, height}), "MAGNASS", sf::Style::Titlebar | sf::Style::Close);
        window.setPosition(sf::Vector2i({x, y}));

        sf::Texture boardTexture;
        if(!boardTexture.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/boards/chess02.jpg")){
                return -1;
        }

        sf::Sprite mainBoard(boardTexture);
        //highlighting the square, we use this piece of code
        sf::RectangleShape pieceSquare(sf::Vector2f({223.f, 294.f}));
        pieceSquare.setFillColor(sf::Color(255, 255, 255, 0)); //make it see-through/transparent
        pieceSquare.setPosition({297.f, 77.f}); //the difference will always be the starting point where to draw the square
        pieceSquare.setOutlineColor(sf::Color::Red);
        pieceSquare.setOutlineThickness(4.f);

        Pieces piece;
        Positions position;


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
                        getSquare(window, *event);
                }

                window.clear(sf::Color::Black);

                window.draw(mainBoard);

                //KING
                piece.king( position.E8, window, 0 );
                piece.king( position.E1, window, 1 );

                //QUEEN
                piece.queen( position.D8, window, 0);
                piece.queen( position.D1, window, 1);

                //PAWN
                piece.pawn( position.A2, window, 1);
                piece.pawn( position.B2, window, 1);
                piece.pawn( position.C2, window, 1);
                piece.pawn( position.D2, window, 1);
                piece.pawn( position.E2, window, 1);
                piece.pawn( position.F2, window, 1);
                piece.pawn( position.G2, window, 1);
                piece.pawn( position.H2, window, 1);

                piece.pawn( position.A7, window, 0);
                piece.pawn( position.B7, window, 0);
                piece.pawn( position.C7, window, 0);
                piece.pawn( position.D7, window, 0);
                piece.pawn( position.E7, window, 0);
                piece.pawn( position.F7, window, 0);
                piece.pawn( position.G7, window, 0);
                piece.pawn( position.H7, window, 0);

                //BISHOP
                piece.bishop( position.F8, window, 0);
                piece.bishop( position.C8, window, 0);
                piece.bishop( position.C1, window, 1);
                piece.bishop( position.F1, window, 1);

                
                //KNIGHT
                piece.knight( position.G8, window, 0);
                piece.knight( position.B8, window, 0);
                piece.knight( position.G1, window, 1);
                piece.knight( position.B1, window, 1);

                //ROOK
                piece.rook( position.A8, window, 0);
                piece.rook( position.H8, window, 0);
                piece.rook( position.A1, window, 1);
                piece.rook( position.H1, window, 1);

                window.draw(pieceSquare);
                

                window.display();
                
        }

        
        return 0;
}