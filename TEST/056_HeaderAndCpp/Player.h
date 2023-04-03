#pragma once

class Player
{
public:
	Player();
	void Damage(int _Damage);

	// 컴파일러가 빌드 안한다.
	void Test();

private:
	int Hp = 100;
	int Att = 10;
};

// int Value = 20;