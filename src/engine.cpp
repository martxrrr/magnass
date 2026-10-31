#include <cstdint>
#include <bitset>
#include <vector>
#include <algorithm>
#include "bitboard.hpp"
#include "engine.hpp"
#include "pieces.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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
    for(int sq = 0; sq < 64; sq++){
        arr_knight_attacks[sq] = gen_knight_moves(sq);
    }
}

uint64_t get_knight_attacks(const Square& square){
    int temp_index = static_cast<int>(square);
    int index = (temp_index % 8) * 8 + (temp_index / 8);
    return arr_knight_attacks[index];
}

void highlight_attacked_squares(sf::RenderWindow &window, const uint64_t &attacks){
    std::string attacked = std::bitset<64>(attacks).to_string();
    std::reverse(attacked.begin(), attacked.end());
   	for(int i = 0; i < 64; ++i){
        int num = attacked[i] - '0';
        if(num == 1){
            int idx = i;
            int row = idx / 8;
            int col = idx % 8;
            // int row = temp_col;
            // int col = temp_row;
            highlightSquare(window, row, col, 245, 72, 66);
        }
    }
}

// void highlight_attacked_squares(sf::RenderWindow &window, const uint64_t &attacks){
//     std::string attacked = std::bitset<64>(attacks).to_string();
//     std::vector<char> bitslist;
// 	for(char c : attacked){
// 		bitslist.emplace_back(c);
// 		if(bitslist.size() == 8){
// 			std::reverse(bitslist.begin(), bitslist.end());
// 			for(int i = 0; i < bitslist.size(); ++i){
//                 int num = attacked[i] - '0';
//                 if(num == 1){
//                     int idx = i;
//                     int row = idx / 8;
//                     int col = idx % 8;

//                     highlightSquare(window, row, col, 245, 72, 66);
//                 }
//             }
// 			bitslist.clear();
// 		}else{
// 			continue;
// 		}
// 	}
// }