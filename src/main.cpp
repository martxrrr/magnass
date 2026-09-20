#include <optional>
#include <cstdint>
#include <unordered_map>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>

#include "pieces.hpp"

void renderPieces(Positions &position, sf::RenderWindow &window);

int main(){

	constexpr int width { 740 };
	constexpr int height { 733 };

	constexpr int x { 100 };
	constexpr int y { 50 };

	sf::RenderWindow window(sf::VideoMode({width, height}), "MAGNASS", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(sf::Vector2i({x, y}));

	sf::Texture boardTexture;
	if(!boardTexture.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/boards/chess02.jpg")){
		return -1;
	}

	sf::Sprite mainBoard(boardTexture);
	Positions position;
	sf::Vector2f coord;

	bool clicked { false };
	bool inRange { false };


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

			if(const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>()){
				if(mouseClick->button == sf::Mouse::Button::Left){
					clicked = true;
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					float mouseX = static_cast<float>(pos.x);
					float mouseY = static_cast<float>(pos.y);

					sf::Vector2f click_position = {mouseX, mouseY};

					if((mouseX > 77 && mouseX < 664) && (mouseY > 77 && mouseY < 664)){
						coord = getSquare(click_position);
						inRange = true;
						std::string squareName = getSquareName(coord);
						std::cout << squareName << "\n";
					}

				}
			}
			
			
		}

		window.clear(sf::Color::Black);

		window.draw(mainBoard);

		renderPieces(position, window);

		if(clicked && inRange){
			highlightSquare(window, coord);
		}

		window.display();
		
	}
	
	return 0;
}

void renderPieces(Positions &position, sf::RenderWindow &window){

		// //KING
		King Bking( position.E8, window, 0 );
		King Wking( position.E1, window, 1 );


		//QUEEN
		Queen Bqueen( position.D8, window, 0);
		Queen Wqueen( position.D1, window, 1);

		//PAWN
		Pawn Wpawn1( position.A2, window, 1);
		Pawn Wpawn2( position.B2, window, 1);
		Pawn Wpawn3( position.C2, window, 1);
		Pawn Wpawn4( position.D2, window, 1);
		Pawn Wpawn5( position.E2, window, 1);
		Pawn Wpawn6( position.F2, window, 1);
		Pawn Wpawn7( position.G2, window, 1);
		Pawn Wpawn8( position.H2, window, 1);

		Pawn Bpawn1( position.A7, window, 0);
		Pawn Bpawn2( position.B7, window, 0);
		Pawn Bpawn3( position.C7, window, 0);
		Pawn Bpawn4( position.D7, window, 0);
		Pawn Bpawn5( position.E7, window, 0);
		Pawn Bpawn6( position.F7, window, 0);
		Pawn Bpawn7( position.G7, window, 0);
		Pawn Bpawn8( position.H7, window, 0);

		//BISHOP
		Bishop Bbishop1( position.F8, window, 0);
		Bishop Bbishop2( position.C8, window, 0);
		Bishop Wbishop1( position.C1, window, 1);
		Bishop Wbishop2( position.F1, window, 1);

		
		//KNIGHT
		Knight Bknight1( position.G8, window, 0);
		Knight Bknight2( position.B8, window, 0);
		Knight Wknight1( position.G1, window, 1);
		Knight Wknight2( position.B1, window, 1);

		//ROOK
		Rook Brook1( position.A8, window, 0);
		Rook Brook2( position.H8, window, 0);
		Rook Wrook1( position.A1, window, 1);
		Rook Wrook2( position.H1, window, 1);

}
