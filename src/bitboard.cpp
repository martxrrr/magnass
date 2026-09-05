#include <iostream>
#include <cstdint>
#include <bit>
#include <bitset>


enum class Square : int {
        SQ_A1 = 0,  SQ_B1 = 1,  SQ_C1 = 2,  SQ_D1 = 3,  SQ_E1 = 4,  SQ_F1 = 5,  SQ_G1 = 6,  SQ_H1 = 7,
        SQ_A2 = 8,  SQ_B2 = 9,  SQ_C2 = 10, SQ_D2 = 11, SQ_E2 = 12, SQ_F2 = 13, SQ_G2 = 14, SQ_H2 = 15,
        SQ_A3 = 16, SQ_B3 = 17, SQ_C3 = 18, SQ_D3 = 19, SQ_E3 = 20, SQ_F3 = 21, SQ_G3 = 22, SQ_H3 = 23,
        SQ_A4 = 24, SQ_B4 = 25, SQ_C4 = 26, SQ_D4 = 27, SQ_E4 = 28, SQ_F4 = 29, SQ_G4 = 30, SQ_H4 = 31,
        SQ_A5 = 32, SQ_B5 = 33, SQ_C5 = 34, SQ_D5 = 35, SQ_E5 = 36, SQ_F5 = 37, SQ_G5 = 38, SQ_H5 = 39,
        SQ_A6 = 40, SQ_B6 = 41, SQ_C6 = 42, SQ_D6 = 43, SQ_E6 = 44, SQ_F6 = 45, SQ_G6 = 46, SQ_H6 = 47,
        SQ_A7 = 48, SQ_B7 = 49, SQ_C7 = 50, SQ_D7 = 51, SQ_E7 = 52, SQ_F7 = 53, SQ_G7 = 54, SQ_H7 = 55,
        SQ_A8 = 56, SQ_B8 = 57, SQ_C8 = 58, SQ_D8 = 59, SQ_E8 = 60, SQ_F8 = 61, SQ_G8 = 62, SQ_H8 = 63,
        SQ_NONE = 64
};


/*  HELPER FUNCTIONS  */

constexpr uint64_t square_bb(Square sq){ 
        return 1ULL << static_cast<unsigned>(sq);          
}
constexpr void set_bit(uint64_t &bb, Square sq){
        bb |= square_bb(sq);        
} 
constexpr void clear_bit(uint64_t &bb, Square sq){
        bb &= ~square_bb(sq);       
}
constexpr void toggle_bit(uint64_t &bb, Square sq) { 
        bb ^= square_bb(sq);        
}
constexpr bool test_bit(uint64_t &bb, Square sq){ 
        return ( bb >> static_cast<unsigned>(sq) ) & 1ULL; 
}


//get the index of the least significant bit
inline Square lsb(uint64_t bb){
        return static_cast<Square>(std::countr_zero(bb));
}

//count the total set bits
inline int popcount(uint64_t bb){
        return std::popcount(bb);
}

//clear the lowest set bit in-place and return its index
inline Square pop_lsb(uint64_t &bb){
        Square sq = lsb(bb);
        bb &= bb  - 1;
        return sq;
}
//WHITE
uint64_t whitePawns = square_bb(Square::SQ_A2) | square_bb(Square::SQ_B2) | square_bb(Square::SQ_C2) | 
                      square_bb(Square::SQ_D2) | square_bb(Square::SQ_E2) | square_bb(Square::SQ_F2) | 
                      square_bb(Square::SQ_G2) | square_bb(Square::SQ_H2) ;

uint64_t whiteKnights = square_bb(Square::SQ_B1) | square_bb(Square::SQ_G1);
uint64_t whiteRooks   = square_bb(Square::SQ_A1) | square_bb(Square::SQ_H1);
uint64_t whiteBishops = square_bb(Square::SQ_C1) | square_bb(Square::SQ_F1);
uint64_t whiteQueen   = square_bb(Square::SQ_D1);
uint64_t whiteKing    = square_bb(Square::SQ_E1);

uint64_t whitePieces = whitePawns   |
                       whiteBishops |
                       whiteKnights | 
                       whiteRooks   |
                       whiteQueen   |
                       whiteKing;

//BLACK
uint64_t blackPawns =   square_bb(Square::SQ_A7) | square_bb(Square::SQ_B7) | square_bb(Square::SQ_C7) | 
                        square_bb(Square::SQ_D7) | square_bb(Square::SQ_E7) | square_bb(Square::SQ_F7) | 
                        square_bb(Square::SQ_G7) | square_bb(Square::SQ_H7) ;

uint64_t blackKnights = square_bb(Square::SQ_B8) | square_bb(Square::SQ_G8);
uint64_t blackRooks   = square_bb(Square::SQ_A8) | square_bb(Square::SQ_H8);
uint64_t blackBishops = square_bb(Square::SQ_C8) | square_bb(Square::SQ_F8);
uint64_t blackQueen   = square_bb(Square::SQ_D8);
uint64_t blackKing    = square_bb(Square::SQ_E8);

uint64_t blackPieces = blackPawns   |
                       blackBishops |
                       blackKnights | 
                       blackRooks   |
                       blackQueen   |
                       blackKing;
void movePiece(uint64_t &type, Square src, Square dst){
	set_bit(type, dst);
	clear_bit(type, src);
}

std::istream& operator >> (std::istream& input, Square& sq){
	std::string userInput;
	input >> userInput;

	if(userInput == "SQ_E2"){
		sq = Square::SQ_E2;
	}
	else if(userInput == "SQ_E4"){
		sq = Square::SQ_E4;
	}
	else if(userInput == "SQ_A8"){
		sq = Square::SQ_A8;
	}
	else if(userInput == "SQ_A6"){
		sq = Square::SQ_A6;
	}
	else{
		input.setstate(std::ios::failbit);
	}
	return input;

}


int main(){
	std::cout << "white piecess before Opening\n" << std::bitset<64>(whitePieces) << "\n";
    
    uint64_t d1 = square_bb(SQ_D1);

    //CHECKING FOR A SPECIFIC PIECE ON A SPECIFIC SQUARE
    if(whiteQueen & d1){
        std::cout << "There is a queen on d1\n\n";
    }else{
        std::cout << "There is no queen on d1\n\n";
    }

    //OCCUPIED
    uint64_t occupied = whitePieces | blackPieces ;
    std::cout << "Occupied Pieces :\n" << std::bitset<64>(occupied) << "\n";

    uint64_t empty_squares = ~occupied;
    std::cout << "Empty Squares :\n" << std::bitset<64>(empty_squares) << "\n";

    
    //CHECKING IF A MOVE IF LEGAL (just learning basics)
    //move a queen from d1 -> d2
    whitePawns = whitePawns << 8;
    whitePieces =      whitePawns   |
                       whiteBishops |
                       whiteKnights | 
                       whiteRooks   |
                       whiteQueen   |
                       whiteKing;

    uint64_t occupiedByWhite = whitePieces;
    uint64_t dest = square_bb(SQ_D2);
    if (dest & occupiedByWhite){
        std::cout << "Illegal move, square already occupied by your piece\n";
    } else {
        std::cout << "Legal move D1 -> D2\n";
        whiteQueen = whiteQueen << 8;
    }
    whitePieces =      whitePawns   |
                       whiteBishops |
                       whiteKnights | 
                       whiteRooks   |
                       whiteQueen   |
                       whiteKing;


	//SIMULATING MOVEMENT OF PIECES
    std::cout << "white pieces after Opening\n" << std::bitset<64>(whitePieces) << "\n";

    std::cout << "White Pawns before : \n" << std::bitset<64>(whitePawns) << "\n";
	
	std::cout << "Black Rooks Before \n" << std::bitset<64>(blackRooks) << "\n";
	uint64_t e2 = square_bb(SQ_E2);

	std::cout << "E2 pawn mask \n" << std::bitset<64>(e2) << "\n";
	if(whitePawns & e2){
		std::cout << "There is a piece on e2 \n";
	}

	//moving a piece -> clear the source and set the destination

	Square pawn_src;
	Square pawn_dst;
	Square rook_src;
	Square rook_dst;

	std::cout << "Pawn (from) : ";
	std::cin >> pawn_src;
	std::cout << "Pawn (to) : ";
	std::cin >> pawn_dst;


	std::cout << "Rook (from) : ";
	std::cin >> rook_src;
	std::cout << "Rook (to) : ";
	std::cin >> rook_dst;

	movePiece(whitePawns, pawn_src, pawn_dst);
	movePiece(blackRooks, rook_src, rook_dst);

	std::cout << "White Pawns After \n" << std::bitset<64>(whitePawns) << "\n";
	std::cout << "Black Rooks After \n" << std::bitset<64>(blackRooks) << "\n";
	

    return 0;
}