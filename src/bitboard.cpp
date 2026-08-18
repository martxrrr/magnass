#include <iostream>
#include <cstdint>
#include <bit>
#include <bitset>


//an enum that reqpresents each square number on the board
enum Square : int {
        SQ_A1 = 0,  SQ_A2 = 1,  SQ_A3 = 2,  SQ_A4 = 3,  SQ_A5 = 4,  SQ_A6 = 5,  SQ_A7 = 6,  SQ_A8 = 7,
        SQ_B1 = 8,  SQ_B2 = 9,  SQ_B3 = 10, SQ_B4 = 11, SQ_B5 = 12, SQ_B6 = 13, SQ_B7 = 14, SQ_B8 = 15,
        SQ_C1 = 16, SQ_C2 = 17, SQ_C3 = 18, SQ_C4 = 19, SQ_C5 = 20, SQ_C6 = 21, SQ_C7 = 22, SQ_C8 = 23,
        SQ_D1 = 24, SQ_D2 = 25, SQ_D3 = 26, SQ_D4 = 27, SQ_D5 = 28, SQ_D6 = 29, SQ_D7 = 30, SQ_D8 = 31,
        SQ_E1 = 32, SQ_E2 = 33, SQ_E3 = 34, SQ_E4 = 35, SQ_E5 = 36, SQ_E6 = 37, SQ_E7 = 38, SQ_E8 = 39,
        SQ_F1 = 40, SQ_F2 = 41, SQ_F3 = 42, SQ_F4 = 43, SQ_F5 = 44, SQ_F6 = 45, SQ_F7 = 46, SQ_F8 = 47,
        SQ_G1 = 48, SQ_G2 = 49, SQ_G3 = 50, SQ_G4 = 51, SQ_G5 = 52, SQ_G6 = 53, SQ_G7 = 54, SQ_G8 = 55,
        SQ_H1 = 56, SQ_H2 = 57, SQ_H3 = 58, SQ_H4 = 59, SQ_H5 = 60, SQ_H6 = 61, SQ_H7 = 62, SQ_H8 = 63,
};

//0000000000001000000000000000000000000000000000000000000000000000
//0000000000000000000000000000000000000000000000000000000000000000
//0000000000001000000000000000000000000000000000000000000000000000 - the result


/*  HELPER FUNCTIONS  */

//returns a 64-bit integer i.e a bitboard or rather it generates a bitboard representation of a square
constexpr uint64_t square_bb(Square sq)             { return 1ULL << sq;          }

//turns on a bit at a certain position i.e sets a bit of a bitboard by performing a bitwise OR
constexpr void set_bit(uint64_t &bb, Square sq)     { bb |= square_bb(sq);        } 

//sets a bit at a certain position to 0
constexpr void clear_bit(uint64_t &bb, Square sq)   { bb &= ~square_bb(sq);       }

//toggles a bit at a certain position i.e 0 to 1 or 1 to 0 using the bitwise XOR operator
constexpr void toggle_bit(uint64_t &bb, Square sq)  { bb ^= square_bb(sq);        }

//returns a boolean, if 0 returns false, if 1 returns true
constexpr bool test_bit(uint64_t &bb, Square sq)    { return ( bb >> sq ) & 1ULL; }


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


int main(){

        uint64_t test = square_bb(SQ_D4);

        auto LSB = lsb(test);
        std::cout << "Index of the lest significant bit : " << LSB << std::endl;

        // set_bit(test, SQ_A1);
        std::cout << "Binary repr : " << std::bitset<64>(test) << "\n";


        //toggling a bit
        toggle_bit(test, SQ_D4);
        toggle_bit(test, SQ_D4);

        std::cout << "Binary repr : " << std::bitset<64>(test) << "\n";

        //testing bit status
        bool val = test_bit(test, SQ_D4);
        std::cout << "Bit status at index " << static_cast<int>(SQ_D4) << " : " << (val ? "Bit On" : "Bit Off") << std::endl;

        //couting the total bits which are ON
        std::cout << "Total set bits : " << popcount(test) << "\n";

        auto poplsb = pop_lsb(test);
        std::cout << poplsb << "\n";

        std::cout << "Binary repr after clearing : " << std::bitset<64>(test) << "\n";

        std::cin.get();



        return 0;
}