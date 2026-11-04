#include <cstdint>
#include <bitset>
#include <vector>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "bitboard.hpp"
#include "engine.hpp"
#include "pieces.hpp"

int square_int(const int &rank, const int &file){
    return (rank * 8) + file;
}

bool check_pseudo_legal(const Square &dest, const uint64_t &attacks){
    uint64_t dst = square_bb(dest);
    return (dst & attacks ? true : false);
}

uint64_t arr_knight_attacks[64];
uint64_t arr_king_attacks[64];

void highlight_attacked_squares(sf::RenderWindow &window, const uint64_t &attacks){
    std::string attacked = std::bitset<64>(attacks).to_string();
    std::reverse(attacked.begin(), attacked.end());
   	for(int i = 0; i < 64; ++i){
        int num = attacked[i] - '0';
        if(num == 1){
            int idx = i;
            int row = idx / 8;
            int col = idx % 8;
            highlightSquare(window, row, col, 245, 72, 66);
        }
    }
}

/*
================================
         THE KNIGHT
================================
*/

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

void knight_attacks(){
    for(int sq = 0; sq < 64; sq++){
        arr_knight_attacks[sq] = gen_knight_moves(sq);
    }
}

uint64_t get_knight_attacks(const Square& square){
    int temp_index = static_cast<int>(square);
    int index = (temp_index % 8) * 8 + (temp_index / 8);
    return arr_knight_attacks[index];
}


/*
================================
         THE KING
================================
*/

uint64_t gen_king_moves(const int& curr_square){
    constexpr int offsets[8][2] = {
		{ 1,   1}, {  0,  1},
		{-1,   1}, { -1,  0},
		{-1,  -1}, {  0, -1},
		{ 1,  -1}, {  1,  0}
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

void king_attacks(){
    for(int sq = 0; sq < 64; sq++){
        arr_king_attacks[sq] = gen_king_moves(sq);
    }
}

uint64_t get_king_attacks(const Square& square){
    int temp_index = static_cast<int>(square);
    int index = (temp_index % 8) * 8 + (temp_index / 8);
    return arr_king_attacks[index];
}

/*
================================
         THE ROOK
================================
advance one square
add it to the attacks
check whether it is occupied
if not continue, if yes, break
*/

uint64_t gen_rook_moves(const int& curr_square, const uint64_t &occupied){
    constexpr int offsets[4][2] = {
        {1, 0}, {0, -1},
        {0, 1}, {-1, 0}
    };
    
    int file = curr_square % 8;
    int rank = curr_square / 8;

    uint64_t attacks = 0;

    for(const auto& offset : offsets){
        int targetFile = file + offset[0];
        int targetRank = rank + offset[1];

        while(targetFile >= 0 && targetFile < 8 && targetRank >= 0 && targetRank < 8){
            int target = square_int(targetFile, targetRank);
            uint64_t target_bb = square_bb(static_cast<Square>(target));

            attacks |= target_bb;
            if(occupied & target_bb){
                break;
            }
            targetFile += offset[0];
            targetRank += offset[1];
        }
    }
    return attacks;
}


/*
================================
         THE BISHOP
================================
same as the rook but with different offsets
*/

uint64_t gen_bishop_moves(const int& curr_square, const uint64_t &occupied){
    constexpr int offsets[4][2] = {
        {1, 1}, {1, -1},
        {-1, -1}, {-1, 1}
    };
    
    int file = curr_square % 8;
    int rank = curr_square / 8;

    uint64_t attacks = 0;

    for(const auto& offset : offsets){
        int targetFile = file + offset[0];
        int targetRank = rank + offset[1];

        while(targetFile >= 0 && targetFile < 8 && targetRank >= 0 && targetRank < 8){
            int target = square_int(targetFile, targetRank);
            uint64_t target_bb = square_bb(static_cast<Square>(target));

            attacks |= target_bb;
            if(occupied & target_bb){
                break;
            }
            targetFile += offset[0];
            targetRank += offset[1];
        }
    }
    return attacks;

}

/*
================================
         THE QUEEN
================================
a combination of a rook and a bishop
*/

uint64_t gen_queen_attacks(const int& curr_square, 
                           const uint64_t &occupied)
{
    return gen_bishop_moves(curr_square, occupied) | 
           gen_rook_moves(curr_square, occupied);
}