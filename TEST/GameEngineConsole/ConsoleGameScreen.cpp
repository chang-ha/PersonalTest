#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::MainScreen;

void ConsoleGameScreen::ScreenClear()
{
	system("cls");
	for (size_t y = 0; y < Size.Y; y++)
	{
		for (size_t x = 0; x < Size.X; x++)
		{
			ArrScreen[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < Size.Y; y++)
	{
		for (size_t x = 0; x < Size.X; x++)
		{
			printf_s("%c", ArrScreen[y][x]);
		}
		printf_s("\n");
	}
}

bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (Size.X <= _Pos.X)
	{
		return true;
	}

	if (Size.Y <= _Pos.Y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}



ConsoleGameScreen::ConsoleGameScreen()
{
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return Size;
}

void ConsoleGameScreen::SetScreenSize(int2 _Size)
{
	Size = _Size;
	// ArrScreen[y][x];
	// char**
	// ArrScreen[y][x] = new char* Arr[y];

	ArrScreen.resize(Size.Y);
	for (size_t i = 0; i < Size.Y; i++)
	{
		// ArrScreen == char**
		// ArrScreen[i] == char*
		ArrScreen[i].resize(Size.X);
	}

}

ConsoleGameScreen::~ConsoleGameScreen()
{
	// 지워지는건 역순
	//for (size_t i = 0; i < Size.Y; i++)
	//{
	//	if (nullptr == ArrScreen[i])
	//	{
	//		continue;
	//	}
	//	delete[] ArrScreen[i];
	//	ArrScreen[i] = nullptr;
	//}
	//if (nullptr == ArrScreen)
	//{
	//	delete[] ArrScreen;
	//	ArrScreen = nullptr;
	//}
}