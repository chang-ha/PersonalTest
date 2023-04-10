#pragma once
#include "ConsoleGameMath.h"
#include "GameEngineArray.h"

class ConsoleGameScreen
{
public:
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

	void SetScreenSize(int2 _Size);
protected:

private:

	char** ArrScreen;

	int2 Size;
	// char�� �迭�� ���� �� �ٸ� �迭
	// GameEngineArray<GameEngineArray<char>> ScreenArr; // == char** ScreenArr;

	ConsoleGameScreen();
	~ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};