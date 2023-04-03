#include <iostream>
#include <conio.h>
#include <Windows.h>

// 전역에 있으면 데이터 영역에 있음
// const int ScreenYsize = 3;
// const int ScreenXsize = 3;

// 위치는 모든 객체가 가지는 "개념"
// 클래스로 만들어야함
// 1단계
class int2
{
public:
	int X;
	int Y;

public:
	int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:
	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};

class ConsoleGameScreen
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
	char Arr[ScreenYSize][ScreenXSize] = {0, };
	// 메모리 영역 자체가 달라졌다고 봐야합니다.
	// 메모리 영역이 어딜지 컴파일러는 알 수가 없음. << 변수
	// 이럴때 2가지 방법을 쓴다.
	// 1. static << 클래스내에 전역변수를 선언
	// 
	//static const int ScreenYsize = 3;
	//static const int ScreenXsize = 3;


	// char Arr[ScreenYsize][ScreenXsize] = {};
};

class Player
{
public:
	int2 GetPos() const
	{
		return Pos;
	}

	void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	void Input()
	{
		if (0 == _kbhit())
		{
			Sleep(InterFrame);
			return;
		}

		char Ch = _getch();
		switch (Ch)
		{
		case 'a':
		case 'A':
			Pos.X -= 1;
			break;
		case 'd':
		case 'D':
			Pos.X + -1;
			break;
		case 'w':
		case 'W':
			Pos.Y -= 1;
			break;
		case 's':
		case 'S':
			Pos.Y += 1;
			break;
		default:
			break;
		}
		Sleep(InterFrame);
	}
protected:

private:
	static const int InterFrame = 200;
	int2 Pos = int2(0, 0);
};

int main()
{
	ConsoleGameScreen NewScreen;
	Player NewPlayer;

	int2 ScreenSize = NewScreen.GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		NewScreen.ScreenClear();

		NewScreen.SetScreenCharacter(NewPlayer.GetPos(), '*');

		NewScreen.ScreenPrint();

		NewPlayer.Input();
	}
	// 게임의 프레임워크와 동일하다
	// 이제부터 내부에서 객체들이 활동하는 것



}
