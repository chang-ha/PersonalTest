#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = EmptySpace;
		}
	}
}

void ConsoleGameScreen::ScreenPrint()
{
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

bool ConsoleGameScreen::IsScreenOver(const ConsoleGameMath & _Pos)
{
	if (0 > _Pos.GetYPos())
	{
		return true;
	}

	if (0 > _Pos.GetXPos())
	{
		return true;
	}

	if (ScreenYSize <= _Pos.GetYPos())
	{
		return true;
	}

	if (ScreenXSize <= _Pos.GetXPos())
	{
		return true;
	}
	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const ConsoleGameMath& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}
	Arr[_Pos.GetYPos()][_Pos.GetXPos()] = _Ch;
}

ConsoleGameScreen::ConsoleGameScreen()
{

}
