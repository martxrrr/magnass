#include <array>
#include <map>
#include <iostream>
#include <algorithm>
#include <bitset>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "pieces.hpp"
#include "bitboard.hpp"

int WIDTH { 656 };
int HEIGHT { 656 };
int X { 100 };
int Y { 50 };
float SQUARES = 8.f;
float BOARD_PX = 656.f;
float sq_size = BOARD_PX / SQUARES;

int sq_id(int &row, int& col){
	return row * SQUARES + col;
}

void highlightSquare(sf::RenderWindow &window, 
					 const int& row, 
					 const int& col, 
					 const int& r, 
					 const int&g, 
					 const int& b)
{
	float sq_x =  4.f + col * sq_size;
	float sq_y =  5.f + (7 - row) * sq_size;

	sf::RectangleShape pieceSquare;
	
	pieceSquare.setSize({sq_size - 4.f, sq_size - 4.f});
	pieceSquare.setFillColor(sf::Color(255, 255, 255, 0));
	pieceSquare.setPosition({sq_x, sq_y});
	pieceSquare.setOutlineColor(sf::Color(r, g, b));
	pieceSquare.setOutlineThickness(3.f);

	window.draw(pieceSquare);
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
	int row = 7 - (square / 8);
	int col = square % 8;

	float offset_x = 8.f;
	float offset_y = 6.f;

	float sp_x =  offset_x + col * sq_size;
	float sp_y =  offset_y + row * sq_size;

	sf::Vector2f coord2{sp_x, sp_y};
	sprite.setPosition(coord2);
	window.draw(sprite);
	
}

uint64_t& getPieceType(const Square& square){
	uint64_t sqbitboard = square_bb(square);

	if(sqbitboard & whitePawns)   return whitePawns;
	if(sqbitboard & whiteKnights) return whiteKnights;
	if(sqbitboard & whiteRooks)   return whiteRooks;
	if(sqbitboard & whiteBishops) return whiteBishops;
	if(sqbitboard & whiteQueen)   return whiteQueen;
	if(sqbitboard & whiteKing)    return whiteKing;

	if(sqbitboard & blackPawns)   return blackPawns;
	if(sqbitboard & blackKnights) return blackKnights;
	if(sqbitboard & blackRooks)   return blackRooks;
	if(sqbitboard & blackBishops) return blackBishops;
	if(sqbitboard & blackQueen)   return blackQueen;
	if(sqbitboard & blackKing)    return blackKing;

	else return none;
}

std::string get_piece_name(const Square& square){
	uint64_t sqbitboard = square_bb(square);

	if(sqbitboard & whitePawns)   return "whitePawns";
	if(sqbitboard & whiteKnights) return "whiteKnights";
	if(sqbitboard & whiteRooks)   return "whiteRooks";
	if(sqbitboard & whiteBishops) return "whiteBishops";
	if(sqbitboard & whiteQueen)   return "whiteQueen";
	if(sqbitboard & whiteKing)    return "whiteKing";

	if(sqbitboard & blackPawns)   return "blackPawns";
	if(sqbitboard & blackKnights) return "blackKnights";
	if(sqbitboard & blackRooks)   return "blackRooks";
	if(sqbitboard & blackBishops) return "blackBishops";
	if(sqbitboard & blackQueen)   return "blackQueen";
	if(sqbitboard & blackKing)    return "blackKing";

	else return "";
}

void binary_board(const std::string &bits){
	std::cout << "=============================\n";
	std::vector<char> bitslist;
	for(char c : bits){
		bitslist.emplace_back(c);
		if(bitslist.size() == 8){
			std::reverse(bitslist.begin(), bitslist.end());
			for(char d : bitslist){
				std::cout << d;
			}
			std::cout << "\n";
			bitslist.clear();
		}else{
			continue;
		}
	}
}

void renderer(sf::RenderWindow& window){
	for(int square = 0; square < 64; square++){
		uint64_t mask = 1ULL << square;

		//RENDER BLACK PIECES
		if(position.blackPawns & mask)   Draw(window, BLACK_PAWNS, square);
		if(position.blackKnights & mask) Draw(window, BLACK_KNIGHTS, square);
		if(position.blackBishops & mask) Draw(window, BLACK_BISHOPS, square);
		if(position.blackRooks & mask)   Draw(window, BLACK_ROOKS, square);
		if(position.blackQueen & mask)   Draw(window, BLACK_QUEEN, square);
		if(position.blackKing & mask)    Draw(window, BLACK_KING, square);

		//RENDER WHITE PIECES
		if(position.whitePawns & mask)   Draw(window, WHITE_PAWNS, square);
		if(position.whiteKnights & mask) Draw(window, WHITE_KNIGHTS, square);
		if(position.whiteBishops & mask) Draw(window, WHITE_BISHOPS, square);
		if(position.whiteRooks & mask)   Draw(window, WHITE_ROOKS, square);
		if(position.whiteQueen & mask)   Draw(window, WHITE_QUEEN, square);
		if(position.whiteKing & mask)    Draw(window, WHITE_KING, square);

	}
}