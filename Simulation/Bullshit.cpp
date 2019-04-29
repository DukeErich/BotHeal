#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

void processMessages(sf::RenderWindow& window) 
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

//вызывает processmessages пока окно не закроется
void waitForClose(sf::RenderWindow& window) 
{
	while (window.isOpen())
	{
		processMessages(window);
	}
}