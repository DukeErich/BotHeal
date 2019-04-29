#include <string>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "RenderConsole.h"
#include "RenderWindow.h"
#include "Game.h"
#include "Bullshit.cpp"

using namespace sf;
using namespace std;

void drawState(const Game& game, RenderWindow& window)
{
	drawStateToConsole(game);
	drawStateToWindow(window, game);
}

int main()
{
	Game game;
	VideoMode video(1200, 900);
	RenderWindow window(video, "window");

	game.initCharacters();

	while (!game.isOver())
	{
		processMessages(window);
		drawState(game, window);
		game.doAllActions();
		game.processResult();
		sleep(milliseconds(100));
	}

	drawState(game, window);
	waitForClose(window);
}