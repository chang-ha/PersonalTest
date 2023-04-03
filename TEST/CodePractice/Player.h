#pragma once
#include "ConsoleGameMath.h"
class Bullet;
class Player
{
public:
	Player();

	inline void SetPos(ConsoleGameMath _Pos)
	{
		Pos = _Pos;
	}

	inline ConsoleGameMath GetPos() const
	{
		return Pos;
	}

	void Input();

	void Render();

	void SetBulletArr(Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}

protected:

private:
	ConsoleGameMath Pos = { 0, 0 };

	int NowBullet = 0;

	Bullet* BulletPtr = nullptr;

	static const int InterFream = 200;
};

