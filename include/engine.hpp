#pragma once
#include <cstdint>
#include <SFML/Graphics.hpp>

extern uint64_t arr_knight_attacks[64];
extern uint64_t arr_king_attacks[64];

void knight_attacks();
void king_attacks();

uint64_t get_knight_attacks(const Square& square);

uint64_t get_king_attacks(const Square& square);

void highlight_attacked_squares(sf::RenderWindow &window, const uint64_t &attacks);

bool check_pseudo_legal(const Square &dest, const uint64_t &attacks);

uint64_t gen_rook_moves(const int& curr_square, const uint64_t &occupied);

uint64_t gen_bishop_moves(const int& curr_square, const uint64_t &occupied);

uint64_t gen_queen_attacks(const int& curr_square, const uint64_t &occupied);