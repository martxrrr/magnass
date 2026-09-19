#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


class King{
	public:
	King(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color);
};

class Queen{
	public:
	Queen(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color);
};

class Rook{
	public:
	Rook(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color);
};

class Knight{
	public:
	Knight(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color);
};

class Bishop{
	public:
	Bishop(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color);
};

class Pawn{
	public:
	Pawn(sf::Vector2f& position,  sf::RenderWindow& window, const uint8_t& color);
};