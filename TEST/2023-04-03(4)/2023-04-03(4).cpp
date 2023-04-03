// 금일 강의 내용 : virtual

#include <iostream>

class Test
{

};


// 다형성을 표현하는 문법인 virtual은 보통 상속과 함께합니다.
// 다형성 == 상속??? XXXXXXXXXXXXXXXXXXXXXXXXXXX (쳐맞습니다)
class FightUnit
{
public:
	int GetAtt()
	{
		return Att;
	}

private:
	int Att= 10;
	int Hp = 100;
};

class Monster : public FightUnit
{

};

class Player : public FightUnit
{
public:
	// 이렇게 짜면 해결가능한가??? << 내 의견 : 임시방편임
	int GetPlayerAtt()
	{
		return GetAtt() + Lv + Equip;
	}

private:
	int Lv = 1;
	int Equip = 1;
};

// 내 게임에 있는 특정 존재들이 싸울때 사용하는 함수
// 이러면 Player나 Boss 등등 객체가 생길때 마다 계속 만들어줘야함
void FightScene(Player* _Player, Monster* _Monster)
{

}

// 그래서 아래처럼 함수를 작성
void Fight(FightUnit* _Player1, FightUnit* _Player2)
{

}
int main()
{
	int Value = sizeof(Test);

	Test Arr[10];

}
