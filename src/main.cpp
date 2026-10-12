#include <optional>
#include <cstdint>
#include <iostream>
#include <bitset>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>

#include "pieces.hpp"
#include "bitboard.hpp"
#include "engine.hpp"

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

	std::vector<Square> enumVec;
	knight_attacks();

	while(window.isOpen()){
		while(const std::optional event = window.pollEvent()){
			if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
				if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
					window.close();
				}
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
						Square squareNum = getSquareNum(squareName);

						enumVec.emplace_back(squareNum);
						Square source;
						Square destination;

						if(enumVec.size() == 2){
							source = enumVec[0];
							destination = enumVec[1];
							if(getPieceType(source) == none){
								enumVec.clear();
							}else{
								uint64_t& piecetyp = getPieceType(source);
								movePiece(piecetyp, source, destination);
								uint64_t knightAttacks = get_knight_attacks(destination);
								std::string bits = std::bitset<64>(knightAttacks).to_string(); 
								binary_board(bits);

								enumVec.clear();
							}
						}
					}
				}
			}
		}

		window.clear(sf::Color::Black);

		window.draw(mainBoard);

		renderer(window);

		if(clicked && inRange){
			highlightSquare(window, coord);
		}

		window.display();
	}
	return 0;
}