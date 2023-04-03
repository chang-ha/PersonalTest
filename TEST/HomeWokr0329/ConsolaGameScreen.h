#pragma once
#include "ConsoleGameMath.h"

class ConsolaGameScreen
{
public:
	// class에 들어오면 변수화 되어버림
	// const int ScreenYsize = 3; 
	// const를 붙이고 초기화까지 해주는 순간 이녀석은 완전히 변하지 않는 수가 되어버린다
	// const int ScreenXsize = 3;
	// 
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static int2 GetScreenSize()
	{
		return int2{ ScreenXSize, ScreenYSize };
	}

	void ScreenClear()
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}
	}

	void ScreenPrint() const
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

	bool IsScreenOver(const int2& _Pos)
	{
		if (0 > _Pos.X)
		{
			return true;
		}

		if (0 > _Pos.Y)
		{
			return true;
		}

		if (ScreenXSize <= _Pos.X)
		{
			return true;
		}

		if (ScreenYSize <= _Pos.Y)
		{
			return true;
		}

		return false;
	}

	void SetScreenCharacter(const int2& _Pos, char _Ch)
	{
		if (true == IsScreenOver(_Pos))
		{
			return;
		}
		Arr[_Pos.Y][_Pos.X] = _Ch;
	}
private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };
	// 메모리 영역 자체가 달라졌다고 봐야합니다.
	// 메모리 영역이 어딜지 컴파일러는 알 수가 없음. << 변수
	// 이럴때 2가지 방법을 쓴다.
	// 1. static << 클래스내에 전역변수를 선언
	// 
	//static const int ScreenYsize = 3;
	//static const int ScreenXsize = 3;


	// char Arr[ScreenYsize][ScreenXsize] = {};

};

