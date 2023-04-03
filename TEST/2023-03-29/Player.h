#pragma once 
// pragma once << "한 cpp파일내의" 헤더 중복 제거
// 다른 cpp에 동일한 헤더 파일이 있으면 중복됨

class Player
{
public:
	Player();
	void Damage(int _Damage);

private:
	int Att = 10;
	int Hp = 100;
};

