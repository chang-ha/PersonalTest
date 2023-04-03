#pragma once

// 헤더에만 다 만든다.
class ConsoleGameMath
{
public:
	inline ConsoleGameMath()
	{

	}

	inline ConsoleGameMath(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}

	inline ConsoleGameMath Half()
	{
		return { X / 2, Y / 2 };
	}

	inline ConsoleGameMath GetPos()
	{
		return { X, Y };
	}

	inline int GetXPos() const
	{
		return X;
	}

	inline int GetYPos() const
	{
		return Y;
	}
	
	inline void SetXPos(int _X)
	{
		X = _X;
	}

	inline void SetYPos(int _Y)
	{
		Y = _Y;
	}
protected:

private:
	int X = 0;
	int Y = 0;
};