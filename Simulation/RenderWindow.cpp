#include "RenderWindow.h"
#include "Warrior.h"
#include "Wolf.h"
#include "Bishop.h"
#include "Game.h"
#include <SFML\Graphics.hpp>

using namespace sf;

const Color HP_COLOR(0, 255, 0);
const Color MP_COLOR(153, 217, 234);
const Vector2f GROUND_POSITION(100, 600);
const float width = 100.0;

void drawBarToWindow(RenderWindow& window, const Vector2f& position, const Color& color, const Bar& bar)
{
	RectangleShape backgound(Vector2f(100, 5));
	backgound.setFillColor(Color(0, 0, 0));
	backgound.setOutlineColor(Color(0, 0, 0));
	backgound.setOutlineThickness(1);
	backgound.setPosition(position);
	backgound.setOrigin(Vector2f(50, 5));
	window.draw(backgound);

	float fillFactor = bar.fillFactor() * width;

	Vector2f size(fillFactor, 5);
	RectangleShape fill(size);
	fill.setFillColor(color);
	fill.setPosition(position);
	fill.setOrigin(Vector2f(50, 5));
	window.draw(fill);
}

void drawGround(RenderWindow& window)
{
	RectangleShape ground(Vector2f(1000, 1));
	ground.setFillColor(Color::Black);
	ground.setPosition(GROUND_POSITION);
	window.draw(ground);
}

void drawWarrior(RenderWindow& window, const Warrior& warrior)
{
	Vector2f warriorPosition((float)warrior.position + GROUND_POSITION.x, GROUND_POSITION.y - 150.0f);
	Vector2f healthBarPosition(warriorPosition.x, warriorPosition.y - 10);
	drawBarToWindow(window, healthBarPosition, HP_COLOR, warrior.hp);
	RectangleShape unit(Vector2f(20, 150));
	unit.setOrigin(Vector2f(10, 0));
	unit.setFillColor(Color(255, 0, 0));
	unit.setPosition(warriorPosition);
	window.draw(unit);
}

void drawWolf(RenderWindow& window, const Wolf& wolf)
{
	CircleShape sprite(50, 10);
	sprite.setFillColor(Color(175, 150, 0));
	sprite.setPosition((float)wolf.position + GROUND_POSITION.x, GROUND_POSITION.y - 100.0f);
	sprite.setOrigin(Vector2f(50, 0));

	const Vector2f& spritePosition = sprite.getPosition();
	Vector2f healthBarPosition(spritePosition.x - 10, spritePosition.y - 15);
	drawBarToWindow(window, healthBarPosition, HP_COLOR, wolf.hp);
	Vector2f mpBarPosition(healthBarPosition.x, healthBarPosition.y + 5);
	drawBarToWindow(window, mpBarPosition, MP_COLOR, wolf.mp);
	window.draw(sprite);
}

void drawBishop(RenderWindow& window, const Bishop& bishop)
{
	Vector2f bishopPosition((float)bishop.position + GROUND_POSITION.x, GROUND_POSITION.y - 30);
	Vector2f healthBarPosition(bishopPosition.x, bishopPosition.y - 40);

	drawBarToWindow(window, healthBarPosition, MP_COLOR, bishop.mp);
	CircleShape sprite(30, 3);
	sprite.setOrigin(30, 30);
	sprite.setPosition(Vector2f(bishopPosition.x, bishopPosition.y));
	sprite.setFillColor(Color(253, 225, 68));
	window.draw(sprite);
	sprite.setRotation(180);
	window.draw(sprite);
}

void drawStateToWindow(RenderWindow& window, const Game& game)
{
	window.clear(Color(255, 255, 255));
	drawGround(window);
	drawWarrior(window, game.warrior);
	drawWolf(window, game.wolf);
	drawBishop(window, game.bishop);
	window.display();
}
