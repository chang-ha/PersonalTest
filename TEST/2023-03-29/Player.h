#pragma once 
// pragma once << "�� cpp���ϳ���" ��� �ߺ� ����
// �ٸ� cpp�� ������ ��� ������ ������ �ߺ���

class Player
{
public:
	Player();
	void Damage(int _Damage);

private:
	int Att = 10;
	int Hp = 100;
};

