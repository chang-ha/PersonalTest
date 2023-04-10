#include "Bomb.h"


Bomb::Bomb()
{
	RenderChar = '@';
}

Bomb::~Bomb()
{

}

void Bomb::Update()
{
	ConsoleGameObject::Update();

	if (0 >= --BombCount)
	{
		Off();
	}
}

void Bomb::Render()
{
	ConsoleGameObject::Render();
	if (false == IsUpdate())
	{
		return;
	}

	if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(Pos))
	{

	}
}