#pragma once

#include <cstdint>

enum class Square;

constexpr uint64_t square_bb(Square sq);
constexpr void set_bit(uint64_t &bb, Square sq);
constexpr void clear_bit(uint64_t &bb, Square sq);
constexpr void toggle_bit(uint64_t &bb, Square sq);
constexpr bool test_bit(uint64_t &bb, Square sq);

Square lsb(uint64_t bb);
int popcount(uint64_t bb);
Square pop_lsb(uint64_t &bb);

extern uint64_t whitePawns;
extern uint64_t whiteKnights;
extern uint64_t whiteRooks  ;
extern uint64_t whiteBishops;
extern uint64_t whiteQueen  ;
extern uint64_t whiteKing   ;

extern uint64_t whitePieces;


//black
extern uint64_t blackPawns;

extern uint64_t blackKnights;
extern uint64_t blackRooks  ;
extern uint64_t blackBishops;
extern uint64_t blackQueen  ;
extern uint64_t blackKing   ;

extern uint64_t blackPieces;

void movePiece(uint64_t &type, Square src, Square dst);

std::istream& operator >> (std::istream& input, Square& sq);