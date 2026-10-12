#include <cstdint>
#include "bitboard.hpp"
#include "engine.hpp"

int square_int(const int &rank, const int &file){
    return (rank * 8) + file;
}

uint64_t gen_knight_moves(const int& curr_square){
    constexpr int offsets[8][2] = {
		{ 1,   2 } , {  2,  1 },
		{ 2,  -1 } , {  1, -2 },
		{-1, -2  } , { -2, -1 },
		{-2,  1  } , { -1,  2 }
	};

    int file = curr_square % 8;
    int rank = curr_square / 8;
    uint64_t attacks = 0;

    for(const auto& offset : offsets){
        int targetFile = file + offset[0];
        int targetRank = rank + offset[1];

        if(targetFile < 0 || targetFile > 8){
            continue;
        }
        if(targetRank < 0 || targetRank > 8){
            continue;
        }
        int tgt = square_int(targetFile, targetRank);
        Square target = static_cast<Square>(tgt);
        attacks |= square_bb(target);
    }
    return attacks;

}

uint64_t arr_knight_attacks[64];

void knight_attacks(){
    for(int sq = 0; sq < 64; ++sq){
        arr_knight_attacks[sq] = gen_knight_moves(sq);
    }
}

uint64_t get_knight_attacks(const Square& square){
    int index = static_cast<int>(square);
    return arr_knight_attacks[index];
}