#include "Item.h"
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineBase/GameEngineRandom.h>

Item::Item()
{
	RenderChar = '&';
	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Half().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Half().Y - 1);
	SetPos({ X, Y});
}

Item::~Item()
{

}

void Item::Update()
{

}
