#pragma once
#include "ConsoleGameMath.h"

class Bullet
{
public:
	static const int ArrBulletCount = 10;

	static Bullet* GetArrBullet()
	{
		return ArrBullet;
	}

	inline void SetPos(const ConsoleGameMath& _Pos)
	{
		Pos = _Pos;
	}

	inline ConsoleGameMath GetPos() const
	{
		return Pos;
	}

	inline bool IsFire() const
	{
		return Fire;
	}

	inline void FireOn()
	{
		Fire = true;
	}

	void Render();

	void Update();

	static void AllRender();

	static void AllUpdate();

protected:

private:
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();

	bool Fire = false;

	ConsoleGameMath Pos = { 0,0 };
};

