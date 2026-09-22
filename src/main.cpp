#include <optional>
#include <cstdint>
#include <unordered_map>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>

#include "pieces.hpp"
#include "bitboard.hpp"

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

		for(int square = 0; square < 64; square++){
			uint64_t mask = 1ULL << square;

			//RENDER BLACK PIECES
			if(blackPawns & mask)   Draw(window, BLACK_PAWNS, square);
			if(blackKnights & mask) Draw(window, BLACK_KNIGHTS, square);
			if(blackBishops & mask) Draw(window, BLACK_BISHOPS, square);
			if(blackRooks & mask)   Draw(window, BLACK_ROOKS, square);
			if(blackQueen & mask)   Draw(window, BLACK_QUEEN, square);
			if(blackKing & mask)    Draw(window, BLACK_KING, square);

			//RENDER WHITE PIECES
			if(whitePawns & mask)   Draw(window, WHITE_PAWNS, square);
			if(whiteKnights & mask) Draw(window, WHITE_KNIGHTS, square);
			if(whiteBishops & mask) Draw(window, WHITE_BISHOPS, square);
			if(whiteRooks & mask)   Draw(window, WHITE_ROOKS, square);
			if(whiteQueen & mask)   Draw(window, WHITE_QUEEN, square);
			if(whiteKing & mask)    Draw(window, WHITE_KING, square);
		}

		if(clicked && inRange){
			highlightSquare(window, coord);
		}

		window.display();
		
	}
	return 0;
}