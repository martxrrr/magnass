#include <iostream>
#include <cstdint>
#include <bit>
#include <bitset>


//an enum that reqpresents each square number on the board
enum Square : int {
        SQ_A1 = 0,  SQ_B1 = 1,  SQ_C1 = 2,  SQ_D1 = 3,  SQ_E1 = 4,  SQ_F1 = 5,  SQ_G1 = 6,  SQ_H1 = 7,
        SQ_A2 = 8,  SQ_B2 = 9,  SQ_C2 = 10, SQ_D2 = 11, SQ_E2 = 12, SQ_F2 = 13, SQ_G2 = 14, SQ_H2 = 15,
        SQ_A3 = 16, SQ_B3 = 17, SQ_C3 = 18, SQ_D3 = 19, SQ_E3 = 20, SQ_F3 = 21, SQ_G3 = 22, SQ_H3 = 23,
        SQ_A4 = 24, SQ_B4 = 25, SQ_C4 = 26, SQ_D4 = 27, SQ_E4 = 28, SQ_F4 = 29, SQ_G4 = 30, SQ_H4 = 31,
        SQ_A5 = 32, SQ_B5 = 33, SQ_C5 = 34, SQ_D4 = 35, SQ_E5 = 36, SQ_F5 = 37, SQ_G5 = 38, SQ_H5 = 39,
        SQ_A6 = 40, SQ_B6 = 41, SQ_C6 = 42, SQ_D6 = 43, SQ_E6 = 44, SQ_F6 = 45, SQ_G6 = 46, SQ_H6 = 47,
        SQ_A7 = 48, SQ_B7 = 49, SQ_C7 = 50, SQ_D7 = 51, SQ_E7 = 52, SQ_F7 = 53, SQ_G7 = 54, SQ_H7 = 55,
        SQ_A8 = 56, SQ_B8 = 57, SQ_C8 = 58, SQ_D8 = 59, SQ_E8 = 60, SQ_F8 = 61, SQ_G8 = 62, SQ_H8 = 63,
        SQ_NONE = 64
};


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