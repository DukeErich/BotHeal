#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class Game;

void drawStateToWindow(sf::RenderWindow& window, const Game& game);