#pragma once

#include <SFML/Graphics.hpp>
#include "bitboard.hpp"

extern sf::Sprite WHITE_PAWNS;
extern sf::Sprite WHITE_BISHOPS;
extern sf::Sprite WHITE_KNIGHTS;
extern sf::Sprite WHITE_ROOKS;
extern sf::Sprite WHITE_QUEEN;
extern sf::Sprite WHITE_KING;

extern sf::Sprite BLACK_PAWNS;
extern sf::Sprite BLACK_BISHOPS;
extern sf::Sprite BLACK_KNIGHTS;
extern sf::Sprite BLACK_ROOKS;
extern sf::Sprite BLACK_QUEEN;
extern sf::Sprite BLACK_KING;


extern int WIDTH;
extern int HEIGHT;
extern int X;
extern int Y;
extern float SQUARES;
extern float BOARD_PX;

extern float sq_size;

sf::Vector2f getSquare(sf::Vector2f &mouseClick);

void highlightSquare(sf::RenderWindow &window, const int& row, const int&col);

void Draw(sf::RenderWindow& window, sf::Sprite& sprite, int square);

void binary_board(const std::string &bits);

void renderer(sf::RenderWindow& window);

uint64_t& getPieceType(const Square& square);

int sq_id(int &row, int& col);