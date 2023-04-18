#pragma once
#include "ConsoleGameMath.h"
#include "GameEngineArray.h"
#include <vector>
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
	std::vector<std::vector<char>> ArrScreen;

	//char** ArrScreen;

	int2 Size;
	// char의 배열을 가진 또 다른 배열
	// GameEngineArray<GameEngineArray<char>> ScreenArr; // == char** ScreenArr;

	ConsoleGameScreen();
	~ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};