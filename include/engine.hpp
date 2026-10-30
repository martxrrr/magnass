#pragma once
#include <cstdint>
#include <SFML/Graphics.hpp>

extern uint64_t arr_knight_attacks[64];

void knight_attacks();

uint64_t get_knight_attacks(const Square& square);

void highlight_attacked_squares(sf::RenderWindow &window, const uint64_t &attacks);