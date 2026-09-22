#include <array>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>

#include "pieces.hpp"

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
	pieceSquare.setOutlineColor(sf::Color::Blue);
	pieceSquare.setOutlineThickness(4.f);

	window.draw(pieceSquare);
}

std::string getSquareName(const sf::Vector2f& mouseCoord){
	std::unordered_map<sf::Vector2f, std::string, Vector2fHash> coordToMap;

	coordToMap[{ 81.f, 597.f }] = "SQ_A1";  coordToMap[{ 154.f, 597.f }] = "SQ_B1";
	coordToMap[{ 81.f, 523.f }] = "SQ_A2";  coordToMap[{ 154.f, 523.f }] = "SQ_B2";
	coordToMap[{ 81.f, 450.f }] = "SQ_A3";  coordToMap[{ 154.f, 450.f }] = "SQ_B3";
	coordToMap[{ 81.f, 377.f }] = "SQ_A4";  coordToMap[{ 154.f, 377.f }] = "SQ_B4";
	coordToMap[{ 81.f, 304.f }] = "SQ_A5";  coordToMap[{ 154.f, 304.f }] = "SQ_B5";
	coordToMap[{ 81.f, 231.f }] = "SQ_A6";  coordToMap[{ 154.f, 231.f }] = "SQ_B6";
	coordToMap[{ 81.f, 153.f }] = "SQ_A7";  coordToMap[{ 154.f, 153.f }] = "SQ_B7";
	coordToMap[{ 81.f, 80.f  }] = "SQ_A8";  coordToMap[{ 154.f, 80.f  }] = "SQ_B8";

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

	coordToMap[{ 520.f, 597.f }] = "SQ_G1";  coordToMap[{ 593.f, 597.f }] = "SQ_H1";
	coordToMap[{ 520.f, 523.f }] = "SQ_G2";  coordToMap[{ 593.f, 523.f }] = "SQ_H2";
	coordToMap[{ 520.f, 450.f }] = "SQ_G3";  coordToMap[{ 593.f, 450.f }] = "SQ_H3";
	coordToMap[{ 520.f, 377.f }] = "SQ_G4";  coordToMap[{ 593.f, 377.f }] = "SQ_H4";
	coordToMap[{ 520.f, 304.f }] = "SQ_G5";  coordToMap[{ 593.f, 304.f }] = "SQ_H5";
	coordToMap[{ 520.f, 231.f }] = "SQ_G6";  coordToMap[{ 593.f, 231.f }] = "SQ_H6";
	coordToMap[{ 520.f, 153.f }] = "SQ_G7";  coordToMap[{ 593.f, 153.f }] = "SQ_H7";
	coordToMap[{ 520.f, 80.f  }] = "SQ_G8";  coordToMap[{ 597.f, 80.f  }] = "SQ_H8";

	auto value = coordToMap.find(mouseCoord);
	if(value != coordToMap.end()){
		return value->second;  
	}else{
		std::cout << "Out of board bound\n";
		return "";
	}
}

class Pieces{
	private:
	// black textures
	sf::Texture pawn;
	sf::Texture bishop;
	sf::Texture knight;
	sf::Texture rook;
	sf::Texture queen;
	sf::Texture king;

	//white textures
	sf::Texture wpawn;
	sf::Texture wbishop;
	sf::Texture wknight;
	sf::Texture wrook;
	sf::Texture wqueen;
	sf::Texture wking;

	public:
	sf::Sprite bp(){
		if(!pawn.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/blackPawn.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite pawnB(pawn);
		return pawnB;
	}

	sf::Sprite bb(){
		if(!bishop.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/blackBishop.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite bishopB(bishop);
		return bishopB;
	}

	sf::Sprite bkn(){
		if(!knight.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/blackKnight.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite knightB(knight);
		return knightB;
	}

	sf::Sprite br(){
		if(!rook.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/blackRook.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite rookB(rook);
		return rookB;
	}

	sf::Sprite bq(){
		if(!queen.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/blackQueen.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite queenB(queen);
		return queenB;
	}

	sf::Sprite bk(){
		if(!king.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/black_pieces/blackKing.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite kingB(king);
		return kingB;
	}

	//WHITE SPRITES

	sf::Sprite wp(){
		if(!wpawn.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/whitePawn.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite pawnW(wpawn);
		return pawnW;
	}

	sf::Sprite wb(){
		if(!wbishop.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/whiteBishop.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite bishopW(wbishop);
		return bishopW;
	}

	sf::Sprite wkn(){
		if(!wknight.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/whiteKnight.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite knightW(wknight);
		return knightW;
	}

	sf::Sprite wr(){
		if(!wrook.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/whiteRook.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite rookW(wrook);
		return rookW;
	}

	sf::Sprite wq(){
		if(!wqueen.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/whiteQueen.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite queenW(wqueen);
		return queenW;
	}

	sf::Sprite wk(){
		if(!wking.loadFromFile("/home/martin/Programming/MAIN/C++/magnass/assets/white_pieces/whiteKing.png")){
			std::cout << "Error loading the image file! " << "\n";
		}
		sf::Sprite kingW(wking);
		return kingW;
	}
};

Pieces piece;

sf::Sprite BLACK_PAWNS = piece.bp();
sf::Sprite BLACK_BISHOPS = piece.bb();
sf::Sprite BLACK_KNIGHTS = piece.bkn();
sf::Sprite BLACK_ROOKS = piece.br();
sf::Sprite BLACK_QUEEN = piece.bq();
sf::Sprite BLACK_KING = piece.bk();

sf::Sprite WHITE_PAWNS = piece.wp();
sf::Sprite WHITE_BISHOPS = piece.wb();
sf::Sprite WHITE_KNIGHTS = piece.wkn();
sf::Sprite WHITE_ROOKS = piece.wr();
sf::Sprite WHITE_QUEEN = piece.wq();
sf::Sprite WHITE_KING = piece.wk();

void Draw(sf::RenderWindow& window, sf::Sprite& sprite, int square){

	std::array<sf::Vector2f, 64> squareToCoord;

	squareToCoord[0]  =  sf::Vector2f({ 81.f, 597.f  });  squareToCoord[1]  =  sf::Vector2f({ 154.f, 597.f });
    squareToCoord[8] = sf::Vector2f({ 81.f, 523.f  });  squareToCoord[9] = sf::Vector2f({ 154.f, 523.f });
    squareToCoord[16] = sf::Vector2f({ 81.f, 450.f  });  squareToCoord[17] = sf::Vector2f({ 154.f, 450.f });
    squareToCoord[24] = sf::Vector2f({ 81.f, 377.f  });  squareToCoord[25] = sf::Vector2f({ 154.f, 377.f });
    squareToCoord[32] = sf::Vector2f({ 81.f, 304.f  });  squareToCoord[33] = sf::Vector2f({ 154.f, 304.f });
    squareToCoord[40] = sf::Vector2f({ 81.f, 231.f  });  squareToCoord[41] = sf::Vector2f({ 154.f, 231.f });
    squareToCoord[48] = sf::Vector2f({ 81.f, 153.f  });  squareToCoord[49] = sf::Vector2f({ 154.f, 153.f });
    squareToCoord[56] = sf::Vector2f({ 81.f, 80.f   });  squareToCoord[57] = sf::Vector2f({ 154.f, 80.f  });
    squareToCoord[2]  =  sf::Vector2f({ 227.f, 597.f });  squareToCoord[3]  =  sf::Vector2f({ 300.f, 600.f });
    squareToCoord[10] = sf::Vector2f({ 227.f, 523.f });  squareToCoord[11] = sf::Vector2f({ 300.f, 523.f });
    squareToCoord[18] = sf::Vector2f({ 227.f, 450.f });  squareToCoord[19] = sf::Vector2f({ 300.f, 450.f });
    squareToCoord[26] = sf::Vector2f({ 227.f, 377.f });  squareToCoord[27] = sf::Vector2f({ 300.f, 377.f });
    squareToCoord[34] = sf::Vector2f({ 227.f, 304.f });  squareToCoord[35] = sf::Vector2f({ 300.f, 304.f });
    squareToCoord[42] = sf::Vector2f({ 227.f, 231.f });  squareToCoord[43] = sf::Vector2f({ 300.f, 231.f });
    squareToCoord[50] = sf::Vector2f({ 227.f, 153.f });  squareToCoord[51] = sf::Vector2f({ 300.f, 153.f });
    squareToCoord[58] = sf::Vector2f({ 227.f, 80.f  });  squareToCoord[59] = sf::Vector2f({ 300.f, 80.f  });
    squareToCoord[4]  =  sf::Vector2f({ 374.f, 597.f });  squareToCoord[5]  =  sf::Vector2f({ 447.f, 597.f });
    squareToCoord[12] = sf::Vector2f({ 374.f, 523.f });  squareToCoord[13] = sf::Vector2f({ 447.f, 523.f });
    squareToCoord[20] = sf::Vector2f({ 374.f, 450.f });  squareToCoord[21] = sf::Vector2f({ 447.f, 450.f });
    squareToCoord[28] = sf::Vector2f({ 374.f, 377.f });  squareToCoord[29] = sf::Vector2f({ 447.f, 377.f });
    squareToCoord[36] = sf::Vector2f({ 374.f, 304.f });  squareToCoord[37] = sf::Vector2f({ 447.f, 304.f });
    squareToCoord[44] = sf::Vector2f({ 374.f, 231.f });  squareToCoord[45] = sf::Vector2f({ 447.f, 231.f });
    squareToCoord[52] = sf::Vector2f({ 374.f, 153.f });  squareToCoord[53] = sf::Vector2f({ 447.f, 153.f });
    squareToCoord[60] = sf::Vector2f({ 374.f, 77.f  });  squareToCoord[61] = sf::Vector2f({ 451.f, 80.f  });
    squareToCoord[6]  =  sf::Vector2f({ 520.f, 597.f });  squareToCoord[7]  =  sf::Vector2f({ 593.f, 597.f });
    squareToCoord[14] = sf::Vector2f({ 520.f, 523.f });  squareToCoord[15] = sf::Vector2f({ 593.f, 523.f });
    squareToCoord[22] = sf::Vector2f({ 520.f, 450.f });  squareToCoord[23] = sf::Vector2f({ 593.f, 450.f });
    squareToCoord[30] = sf::Vector2f({ 520.f, 377.f });  squareToCoord[31] = sf::Vector2f({ 593.f, 377.f });
    squareToCoord[38] = sf::Vector2f({ 520.f, 304.f });  squareToCoord[39] = sf::Vector2f({ 593.f, 304.f });
    squareToCoord[46] = sf::Vector2f({ 520.f, 231.f });  squareToCoord[47] = sf::Vector2f({ 593.f, 231.f });
    squareToCoord[54] = sf::Vector2f({ 520.f, 153.f });  squareToCoord[55] = sf::Vector2f({ 593.f, 153.f });
    squareToCoord[62] = sf::Vector2f({ 520.f, 80.f  });  squareToCoord[63] = sf::Vector2f({ 597.f, 80.f  });

	sf::Vector2f coord = squareToCoord[square];
	sprite.setPosition(coord);
	window.draw(sprite);
	
}