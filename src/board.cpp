#include <iostream>
#include <optional>
#include <cstdint>
#include <typeinfo>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "board.hpp"

sf::Vector2f getSquare(sf::Vector2f &mouseClick);
void highlightSquare(sf::RenderWindow &window, sf::Vector2f &cordinate);
sf::Vector2f getClick(sf::RenderWindow &window, const sf::Event &event);


int main(){

        constexpr int width { 740 };
        constexpr int height { 733 };

        constexpr int x { 50 };
        constexpr int y { 50 };

        sf::RenderWindow window(sf::VideoMode({width, height}), "MAGNASS", sf::Style::Titlebar | sf::Style::Close);
        window.setPosition(sf::Vector2i({x, y}));

        sf::Texture boardTexture;
        if(!boardTexture.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/boards/chess02.jpg")){
                return -1;
        }

        sf::Sprite mainBoard(boardTexture);

        Pieces piece;
        Positions position;


        while(window.isOpen()){
                sf::Vector2f mouse;
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
                        sf::Vector2f mousePos = getClick(window, *event);
                        mouse = mousePos;
                        
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

                sf::Vector2f coord = getSquare(mouse);
                highlightSquare(window, coord);

                

                window.display();
                
        }

        
        return 0;
}
sf::Vector2f getClick(sf::RenderWindow &window, const sf::Event &event){
        if(const auto* mouseClick = event.getIf<sf::Event::MouseButtonPressed>()){
                if(mouseClick->button == sf::Mouse::Button::Left){
                        sf::Vector2i pos = sf::Mouse::getPosition(window);
                        float mouseX = static_cast<float>(pos.x);
                        float mouseY = static_cast<float>(pos.y);

                        sf::Vector2f click_position = {mouseX, mouseY};

                        return click_position;
                }
        }
}

sf::Vector2f getSquare(sf::Vector2f &mouseClick){
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
        
        
        float diffX{};
        float diffY{};

        std::array<double, 4> euclideans;
        sf::Vector2f closest = { };
        
        //calculate the euclidean distances and append them in an std::array
        for(auto position{ 0 }; position < 4; position++){
                diffX = pow((positions[position].x - mouseClick.x), 2);
                diffY = pow((positions[position].y - mouseClick.y), 2);
                double sum { diffX + diffY };

                double euclidean { sqrt(sum) };
                euclideans[position] = euclidean;
        }

        //sort the array and get the smallest euclidean distance
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

                // //print out the sorted euclideans
                // for(auto k { 0 }; k < virtualEuclideans.size(); k++){
                //         std::cout << virtualEuclideans[k] << "\n";
                // }

                // //print out the unsorted euclideans
                // std::cout << std::endl;
                // for(auto l { 0 }; l < euclideans.size(); l++){
                //         std::cout << euclideans[l] << "\n";
                // }

                //pick out the smallest euclidean distance value
                close = virtualEuclideans[0];
        }

        int index;

        for(int j { 0 }; j < euclideans.size(); j++){
                int idx;
                if(euclideans[j] == close){
                        idx = j;
                }else{
                        continue;
                }
        index = idx;
        }

        //now here we have the cordinate of the closest render point from the mouse click point
        closest = {positions[index].x, positions[index].y}; //this is an sf::Vector2f object

        std::cout << closest.x << " " << closest.y << "\n";

        return closest;

}

void highlightSquare(sf::RenderWindow &window, sf::Vector2f &cordinate){
        //highlighting the square, we use this piece of code
        sf::RectangleShape pieceSquare(sf::Vector2f({71.f, 71.f}));
        pieceSquare.setFillColor(sf::Color(255, 255, 255, 0)); //make it see-through/transparent
        pieceSquare.setPosition(cordinate); //the difference will always be the starting point where to draw the square
        pieceSquare.setOutlineColor(sf::Color::Red);
        pieceSquare.setOutlineThickness(4.f);

        window.draw(pieceSquare);


}