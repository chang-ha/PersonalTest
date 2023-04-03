#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen
{
public:
	static const int ScreenXSize = 5;
	static const int ScreenYSize = 5;
	static const char EmptySpace = 'a';

	inline static ConsoleGameScreen& GetScreen()
	{
		return MainScreen;
	}
	inline static ConsoleGameMath GetScreenSize()
	{
		return { ScreenXSize, ScreenYSize };
	}

	void ScreenClear();

	void ScreenPrint();

	bool IsScreenOver(const ConsoleGameMath& _Pos);

	void SetScreenCharacter(const ConsoleGameMath& _Pos, char _Ch);

protected:

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0 };

	static ConsoleGameScreen MainScreen;

	ConsoleGameScreen();
};

