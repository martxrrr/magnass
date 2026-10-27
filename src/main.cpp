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
	sf::RenderWindow window(
							sf::VideoMode({static_cast<unsigned int>(WIDTH), 
							static_cast<unsigned int>(HEIGHT)}), 
							"MAGNASS", sf::Style::Titlebar | 
							sf::Style::Close);

	window.setPosition(sf::Vector2i({X, Y}));

	sf::Texture boardTexture;
	if(!boardTexture.loadFromFile("assets/boards/boardC.png")){
		return -1;
	}

    sf::Sprite mainBoard(boardTexture);
	Positions position;
	sf::Vector2f coord;
	int sqid;

	sf::Vector2f target{656.f, 656.f};
	auto size = sf::Vector2f(boardTexture.getSize());
	mainBoard.setScale({target.x / size.x, target.y / size.y});

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

					int click_x = pos.x;
					int click_y = pos.y;

					int col = click_x / SQ_LEN;
					int row = click_y / SQ_LEN;
					sqid = sq_id(row, col);

					std::cout << "X : " << mouseX << " Y : " << mouseY << std::endl;

					sf::Vector2f click_position = {mouseX, mouseY};

					if((mouseX > 50 && mouseX < 685) && (mouseY > 45 && mouseY < 680)){
						inRange = true;
						// coord = getSquare(click_position); //returns coordinates of that square
						// std::string squareName = getSquareName(coord);
						Square squareNum = static_cast<Square>(sqid);

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
								// std::string bits = std::bitset<64>(knightAttacks).to_string(); 
								// binary_board(bits);
								
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
			highlightSquare(window, sqid);
		}

		window.display();
	}
	return 0;
}