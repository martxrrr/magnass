#include <iostream>
#include <cstdint>
#include <bit>

#include "bitboard.hpp"

/*  HELPER FUNCTIONS  */

// get the index of the least significant bit
Square lsb(uint64_t bb){
    return static_cast<Square>(std::countr_zero(bb));
}

//count the total set bits
int bits_count(uint64_t bb){
    return std::popcount(bb);
}

// clear the lowest set bit in-place and return its index
Square pop_lsb(uint64_t &bb){
    Square sq = lsb(bb);
    bb &= bb  - 1;
    return sq;
}
//WHITE
inline uint64_t whitePawns = square_bb(Square::SQ_A2) |
					         square_bb(Square::SQ_C2) |
                             square_bb(Square::SQ_E2) | 
                             square_bb(Square::SQ_G2) |
                             square_bb(Square::SQ_B2) |
                             square_bb(Square::SQ_D2) |
                             square_bb(Square::SQ_F2) |
                             square_bb(Square::SQ_H2) ;

inline uint64_t whiteKnights = square_bb(Square::SQ_B1) |
                               square_bb(Square::SQ_G1) ;
inline uint64_t whiteRooks   = square_bb(Square::SQ_A1) | 
                               square_bb(Square::SQ_H1) ;
inline uint64_t whiteBishops = square_bb(Square::SQ_C1) | 
                               square_bb(Square::SQ_F1) ;
inline uint64_t whiteQueen   = square_bb(Square::SQ_D1) ;
inline uint64_t whiteKing    = square_bb(Square::SQ_E1) ;

inline uint64_t whitePieces = whitePawns   |
                              whiteBishops |
                              whiteKnights | 
                              whiteRooks   |
                              whiteQueen   |
                              whiteKing;

//BLACK
inline uint64_t blackPawns =   square_bb(Square::SQ_A7) |
					           square_bb(Square::SQ_C7) |
                               square_bb(Square::SQ_E7) | 
                               square_bb(Square::SQ_G7) |
                               square_bb(Square::SQ_B7) |
                               square_bb(Square::SQ_D7) |
                               square_bb(Square::SQ_F7) |
                               square_bb(Square::SQ_H7) ;

inline uint64_t blackKnights = square_bb(Square::SQ_B8) | 
                               square_bb(Square::SQ_G8) ;
inline uint64_t blackRooks   = square_bb(Square::SQ_A8) | 
                               square_bb(Square::SQ_H8) ;
inline uint64_t blackBishops = square_bb(Square::SQ_C8) | 
                               square_bb(Square::SQ_F8) ;
inline uint64_t blackQueen   = square_bb(Square::SQ_D8) ;
inline uint64_t blackKing    = square_bb(Square::SQ_E8) ;

inline uint64_t blackPieces = blackPawns   |
                              blackBishops |
                              blackKnights | 
                              blackRooks   |
                              blackQueen   |
                              blackKing    ;

inline uint64_t none = square_bb(Square::SQ_NONE);

int WHITE = 1;
int BLACK = 0;
int LOCK = 1;

void move(int &piecetype, int &lock){
	if(lock == 1 && piecetype == WHITE){
		lock = 1 - lock;
	}
	else if(lock == 0 && piecetype == BLACK){
		lock = 1 - lock;
	}
}

void movePiece(uint64_t &type, Square &src, Square &dst){
    int sq = static_cast<int>(src);
    if((whitePieces & (1ULL << sq)) && LOCK == 1){
        std::cout << "White piece clicked!\n";
        clear_bit(type, src);
        set_bit(type, dst);
        move(WHITE, LOCK);
    }
    if((blackPieces & (1ULL << sq)) && LOCK == 0){
        std::cout << "Black piece clicked!\n";
        clear_bit(type, src);
        set_bit(type, dst);
        move(BLACK, LOCK);
    }
}

boardPosition position{
    whitePawns,
    whiteKnights,
    whiteBishops,
    whiteRooks,
    whiteQueen,
    whiteKing,
    whitePieces,
    blackPawns,
    blackKnights,
    blackBishops,
    blackRooks,
    blackQueen,
    blackKing,
    blackPieces,
    none
};