#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

sf::Vector2f getSquare(sf::Vector2f &mouseClick);

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

void highlightSquare(sf::RenderWindow &window, sf::Vector2f &cordinate);

void Draw(sf::RenderWindow& window, sf::Sprite& sprite, int square);

std::string getSquareName(const sf::Vector2f& mouseCoord);

struct Vector2fHash{
	std::size_t operator()(const sf::Vector2f& v) const {
		std::size_t h1 = std::hash<float>{}(v.x);
		std::size_t h2 = std::hash<float>{}(v.y);

		return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
	}
};

struct Positions{

		sf::Vector2f A1 = { 81.f, 597.f  };  sf::Vector2f B1 = { 154.f, 597.f };
		sf::Vector2f A2 = { 81.f, 523.f  };  sf::Vector2f B2 = { 154.f, 523.f };
		sf::Vector2f A3 = { 81.f, 450.f  };  sf::Vector2f B3 = { 154.f, 450.f };
		sf::Vector2f A4 = { 81.f, 377.f  };  sf::Vector2f B4 = { 154.f, 377.f };
		sf::Vector2f A5 = { 81.f, 304.f  };  sf::Vector2f B5 = { 154.f, 304.f };
		sf::Vector2f A6 = { 81.f, 231.f  };  sf::Vector2f B6 = { 154.f, 231.f };
		sf::Vector2f A7 = { 81.f, 153.f  };  sf::Vector2f B7 = { 154.f, 153.f };
		sf::Vector2f A8 = { 81.f, 80.f   };  sf::Vector2f B8 = { 154.f, 80.f  };

		sf::Vector2f C1 = { 227.f, 597.f };  sf::Vector2f D1 = { 300.f, 600.f };
		sf::Vector2f C2 = { 227.f, 523.f };  sf::Vector2f D2 = { 300.f, 523.f };
		sf::Vector2f C3 = { 227.f, 450.f };  sf::Vector2f D3 = { 300.f, 450.f };
		sf::Vector2f C4 = { 227.f, 377.f };  sf::Vector2f D4 = { 300.f, 377.f };
		sf::Vector2f C5 = { 227.f, 304.f };  sf::Vector2f D5 = { 300.f, 304.f };
		sf::Vector2f C6 = { 227.f, 231.f };  sf::Vector2f D6 = { 300.f, 231.f };
		sf::Vector2f C7 = { 227.f, 153.f };  sf::Vector2f D7 = { 300.f, 153.f };
		sf::Vector2f C8 = { 227.f, 80.f  };  sf::Vector2f D8 = { 300.f, 80.f  };

		sf::Vector2f E1 = { 374.f, 597.f };  sf::Vector2f F1 = { 447.f, 597.f };
		sf::Vector2f E2 = { 374.f, 523.f };  sf::Vector2f F2 = { 447.f, 523.f };
		sf::Vector2f E3 = { 374.f, 450.f };  sf::Vector2f F3 = { 447.f, 450.f };
		sf::Vector2f E4 = { 374.f, 377.f };  sf::Vector2f F4 = { 447.f, 377.f };
		sf::Vector2f E5 = { 374.f, 304.f };  sf::Vector2f F5 = { 447.f, 304.f };
		sf::Vector2f E6 = { 374.f, 231.f };  sf::Vector2f F6 = { 447.f, 231.f };
		sf::Vector2f E7 = { 374.f, 153.f };  sf::Vector2f F7 = { 447.f, 153.f };
		sf::Vector2f E8 = { 374.f, 77.f  };  sf::Vector2f F8 = { 451.f, 80.f  };

		sf::Vector2f G1 = { 520.f, 597.f };  sf::Vector2f H1 = { 593.f, 597.f };
		sf::Vector2f G2 = { 520.f, 523.f };  sf::Vector2f H2 = { 593.f, 523.f };
		sf::Vector2f G3 = { 520.f, 450.f };  sf::Vector2f H3 = { 593.f, 450.f };
		sf::Vector2f G4 = { 520.f, 377.f };  sf::Vector2f H4 = { 593.f, 377.f };
		sf::Vector2f G5 = { 520.f, 304.f };  sf::Vector2f H5 = { 593.f, 304.f };
		sf::Vector2f G6 = { 520.f, 231.f };  sf::Vector2f H6 = { 593.f, 231.f };
		sf::Vector2f G7 = { 520.f, 153.f };  sf::Vector2f H7 = { 593.f, 153.f };
		sf::Vector2f G8 = { 520.f, 80.f  };  sf::Vector2f H8 = { 597.f, 80.f  };

};