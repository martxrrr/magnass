#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>

#include "pieces.hpp"

King::King(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
Queen::Queen(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
Rook::Rook(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
Bishop::Bishop(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
Pawn::Pawn(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
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
Knight::Knight(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color){
		sf::Texture knight;
		if(color == 0){
				if(!knight.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/knightB.png")){
						std::cout << "Error loading the image file! " << "\n";
				}
				sf::Sprite knightB(knight);
				knightB.setScale({-1.0f, 1.0f});
				knightB.setPosition({position});

				window.draw(knightB);
		}else if(color == 1){
				if(!knight.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/knightW.png")){
						std::cout << "Error loading the image file! " << "\n";
				}
				sf::Sprite knightW(knight);
				knightW.setScale({-1.0f, 1.0f});
				knightW.setPosition({position});

				window.draw(knightW);
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

	std::array<double, 63> euclideans;
	sf::Vector2f closest = { };
	
	for(auto pos{ 0 }; pos < positions.size() - 1; pos++){
		diffX = pow((positions[pos].x - mouseClick.x), 2);
		diffY = pow((positions[pos].y - mouseClick.y), 2);
		double sum { diffX + diffY };

		double euclidean { sqrt(sum) };
		euclideans[pos] = euclidean;
	}

	double close { };
	{
		std::array<double, 63> virtualEuclideans;
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

	closest = {positions[index].x, positions[index].y};

	return closest;

}

void highlightSquare(sf::RenderWindow &window, sf::Vector2f &cordinate){
	sf::Vector2f coordinate = cordinate;
	sf::RectangleShape pieceSquare(sf::Vector2f({67.f, 70.f}));
	pieceSquare.setFillColor(sf::Color(255, 255, 255, 0));
	pieceSquare.setPosition({coordinate.x, coordinate.y - 4.f});
	pieceSquare.setOutlineColor(sf::Color::Green);
	pieceSquare.setOutlineThickness(4.f);

	window.draw(pieceSquare);
}


std::string getSquareName(const sf::Vector2f& mouseCoord){
	std::unordered_map<sf::Vector2f, std::string, Vector2fHash> coordToMap;

	coordToMap[{ 81.f, 597.f }] = "SQ_A1";  coordToMap[{ 223.f, 597.f }] = "SQ_B1";
	coordToMap[{ 81.f, 523.f }] = "SQ_A2";  coordToMap[{ 154.f, 523.f }] = "SQ_B2";
	coordToMap[{ 81.f, 450.f }] = "SQ_A3";  coordToMap[{ 154.f, 450.f }] = "SQ_B3";
	coordToMap[{ 81.f, 377.f }] = "SQ_A4";  coordToMap[{ 154.f, 377.f }] = "SQ_B4";
	coordToMap[{ 81.f, 304.f }] = "SQ_A5";  coordToMap[{ 154.f, 304.f }] = "SQ_B5";
	coordToMap[{ 81.f, 231.f }] = "SQ_A6";  coordToMap[{ 154.f, 231.f }] = "SQ_B6";
	coordToMap[{ 81.f, 153.f }] = "SQ_A7";  coordToMap[{ 154.f, 153.f }] = "SQ_B7";
	coordToMap[{ 81.f, 80.f  }] = "SQ_A8";  coordToMap[{ 223.f, 80.f  }] = "SQ_B8";

	coordToMap[{ 227.f, 597.f }] = "SQ_C1";  coordToMap[{ 300.f, 600.f }] = "SQ_D1";
	coordToMap[{ 227.f, 523.f }] = "SQ_C2";  coordToMap[{ 300.f, 523.f }] = "SQ_D2";
	coordToMap[{ 227.f, 450.f }] = "SQ_C3";  coordToMap[{ 300.f, 450.f }] = "SQ_D3";
	coordToMap[{ 227.f, 377.f }] = "SQ_C4";  coordToMap[{ 300.f, 377.f }] = "SQ_D4";
	coordToMap[{ 227.f, 304.f }] = "SQ_C5";  coordToMap[{ 300.f, 304.f }] = "SQ_D5";
	coordToMap[{ 227.f, 231.f }] = "SQ_C6";  coordToMap[{ 300.f, 231.f }] = "SQ_D6";
	coordToMap[{ 227.f, 153.f }] = "SQ_C7";  coordToMap[{ 300.f, 153.f }] = "SQ_D7";
	coordToMap[{ 227.f, 80.f  }] = "SQ_C8";  coordToMap[{ 300.f, 80.f  }] = "SQ_D8";


	coordToMap[{ 374.f, 597.f }] = "SQ_E1";  coordToMap[{ 447.f, 597.f }] = "SQ_F1";
	coordToMap[{ 374.f, 523.f }] = "SQ_E2";  coordToMap[{ 447.f, 523.f }] = "SQ_F2";
	coordToMap[{ 374.f, 450.f }] = "SQ_E3";  coordToMap[{ 447.f, 450.f }] = "SQ_F3";
	coordToMap[{ 374.f, 377.f }] = "SQ_E4";  coordToMap[{ 447.f, 377.f }] = "SQ_F4";
	coordToMap[{ 374.f, 304.f }] = "SQ_E5";  coordToMap[{ 447.f, 304.f }] = "SQ_F5";
	coordToMap[{ 374.f, 231.f }] = "SQ_E6";  coordToMap[{ 447.f, 231.f }] = "SQ_F6";
	coordToMap[{ 374.f, 153.f }] = "SQ_E7";  coordToMap[{ 447.f, 153.f }] = "SQ_F7";
	coordToMap[{ 374.f, 77.f  }] = "SQ_E8";  coordToMap[{ 451.f, 80.f  }] = "SQ_F8";


	coordToMap[{ 589.f, 597.f }] = "SQ_G1";  coordToMap[{ 593.f, 597.f }] = "SQ_H1";
	coordToMap[{ 520.f, 523.f }] = "SQ_G2";  coordToMap[{ 593.f, 523.f }] = "SQ_H2";
	coordToMap[{ 520.f, 450.f }] = "SQ_G3";  coordToMap[{ 593.f, 450.f }] = "SQ_H3";
	coordToMap[{ 520.f, 377.f }] = "SQ_G4";  coordToMap[{ 593.f, 377.f }] = "SQ_H4";
	coordToMap[{ 520.f, 304.f }] = "SQ_G5";  coordToMap[{ 593.f, 304.f }] = "SQ_H5";
	coordToMap[{ 520.f, 231.f }] = "SQ_G6";  coordToMap[{ 593.f, 231.f }] = "SQ_H6";
	coordToMap[{ 520.f, 153.f }] = "SQ_G7";  coordToMap[{ 593.f, 153.f }] = "SQ_H7";
	coordToMap[{ 589.f, 80.f  }] = "SQ_G8";  coordToMap[{ 597.f, 80.f  }] = "SQ_H8";

	auto value = coordToMap.find(mouseCoord);
	if(value != coordToMap.end()){
		// std::cout << "Square ==> " << value->second << std::endl;
		return value->second;  
	}else{
		std::cout << "Out of board bound\n";
		return "";
	}
	
}