#include <iostream>
#include <cstdint>
#include <bit>
#include <bitset>

#include "bitboard.hpp"

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
Square lsb(uint64_t bb){
    return static_cast<Square>(std::countr_zero(bb));
}

//count the total set bits
int popcount(uint64_t bb){
    return std::popcount(bb);
}

//clear the lowest set bit in-place and return its index
Square pop_lsb(uint64_t &bb){
    Square sq = lsb(bb);
    bb &= bb  - 1;
    return sq;
}
//WHITE
uint64_t whitePawns = square_bb(Square::SQ_A2) |
					  square_bb(Square::SQ_C2) |
                      square_bb(Square::SQ_E2) | 
                      square_bb(Square::SQ_G2) |
                      square_bb(Square::SQ_B2) |
                      square_bb(Square::SQ_D2) |
                      square_bb(Square::SQ_F2) |
                      square_bb(Square::SQ_H2) ;

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
uint64_t blackPawns =   square_bb(Square::SQ_A7) |
					    square_bb(Square::SQ_C7) |
                        square_bb(Square::SQ_E7) | 
                        square_bb(Square::SQ_G7) |
                        square_bb(Square::SQ_B7) |
                        square_bb(Square::SQ_D7) |
                        square_bb(Square::SQ_F7) |
                        square_bb(Square::SQ_H7) ;

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