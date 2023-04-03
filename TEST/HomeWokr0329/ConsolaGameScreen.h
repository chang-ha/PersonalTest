#pragma once
#include "ConsoleGameMath.h"

class ConsolaGameScreen
{
public:
	// class�� ������ ����ȭ �Ǿ����
	// const int ScreenYsize = 3; 
	// const�� ���̰� �ʱ�ȭ���� ���ִ� ���� �̳༮�� ������ ������ �ʴ� ���� �Ǿ������
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
	// �޸� ���� ��ü�� �޶����ٰ� �����մϴ�.
	// �޸� ������ ����� �����Ϸ��� �� ���� ����. << ����
	// �̷��� 2���� ����� ����.
	// 1. static << Ŭ�������� ���������� ����
	// 
	//static const int ScreenYsize = 3;
	//static const int ScreenXsize = 3;


	// char Arr[ScreenYsize][ScreenXsize] = {};

};

