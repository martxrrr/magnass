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
	if(!boardTexture.loadFromFile("assets/boards/boardA.png")){
		return -1;
	}

    sf::Sprite mainBoard(boardTexture);
	mainBoard.setPosition({0.f, 0.f});

	sf::Vector2f target{656.f, 656.f};
	auto size = sf::Vector2f(boardTexture.getSize());
	mainBoard.setScale({target.x / size.x, target.y / size.y});
	
	knight_attacks();
	Params args;

	while(window.isOpen()){
		while(const std::optional event = window.pollEvent()){
			if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
				if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
					window.close();
				}
			}
			if(const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>()){
				if(mouseClick->button == sf::Mouse::Button::Left){
					mini_main(args, window);
				}
			}
		}

		window.clear(sf::Color::Black);

		window.draw(mainBoard);

		renderer(window);

		if(args.clicked){
			highlightSquare(window, args.row, args.col,230, 245, 66);
		}
		// highlight_attacked_squares(window, args.attacked_squares);

		window.display();
	}
	return 0;
}