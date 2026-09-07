#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class King{
		public:
		King(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
		
};

class Queen{
		public:
		Queen(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
};

class Rook{
		public:
		Rook(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
};

class Bishop{
		public:
		Bishop(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
};

class Knight{
		public:
		Knight(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
};

class Pawn{
		public:
		Pawn(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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


//coordinates where to render
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