// 금일 강의 내용 :class constructor (리터럴 초기화, 멤버 이니셜라이저, 리스트 이니셜라이저)

#include <iostream>

class Weapon
{
public:
	int Att = 200;
public:
	Weapon()
	{

	}
};

class Potion
{
public:
	int Heal = 100;
public:
	Potion()
	{

	}
};

class Player
{
public:
	// 리터럴 초기화
	// 11 이전에는 안됐던 방식이고 회사에서 사용하지 않을수도 있다.
	// 변수를 선언하고 바로 초기화하는 방법
	int HP = 20;
	int Att = 20;
	int Maxatt = 20;
	int Minatt = 20;
	int PDef = 20;
	int MDef = 20;
	int Crit = 20;

	Weapon PlayerWeapon = Weapon();
	Potion PlayerPotion = Potion();

	void TestFunction()
	{
	}

	// class 생성자 함수의 이름은
	// "무조건 class 이름과 완전히 동일해야 합니다."
	// "객체없이 호출가능" << 일반적인 클래스의 함수는 무조건 객체가 필요한데,
	//						객체를 만드는 함수가 객체가 필요하면 모순이 생겨버림
	// "리턴값이 없다." << 눈에 보이진 않지만 플레이어를 리턴함
	// "멤버이니셜라이저"라는 문법을 사용할 수 있음
	// "리터럴 초기화"와 "멤버이니셜라이저"가 동시에 사용되면 "멤버이니셜라이저"가 나중에 적용되기 때문에
	// 멤버의 값들은 "멤버이니셜라이저"값들이 들어감
	Player()
		: HP(30), Att(30), Maxatt(30), Minatt(30), PDef(30), MDef(30), Crit(30) // 멤버변수 선언시 해당 값들이 들어감
	{
		// 안에도 코드를 칠 수 있음
		HP = 10; // << 이는 대입연산
	}

	// 이렇게 만드는게 보기 좋음
	//Player()			
	//	: HP(30),
	//	Att(30),
	//	Maxatt(30),
	//	Minatt(30),
	//	PDef(30),
	//	MDef(30),
	//	Crit(30)
	//{
	//}

	// 리터럴 초기화 or 멤버이니셜라이저 둘 중에는 무조건 하나는 초기화 해야함
private:
};

class Player2
{
public:
	Player2(int _Value)
	{
	}
};

class Player3
{
public:
	Player3(int _Value0, int _Value1)
	{
	}
};

void Test(const Player& _Player)
{
}

int main()
{
	// class를 만들었는데 내가 정의하지 않는 행동을 할 수 있다면
	// 그건 컴파일러가 그렇게 한거다. (그리고 보통 생략되어 있음)
	Player NewPlayer = Player(); // << Player() 함수를 만든적이 없는데 된다

	// int와 내가 만든 Player는 문법적으로 전혀 차이가 없음
	int Value = int(20);
	Player2 NewPlayer2 = Player2(20);

	int Value2 = 20;
	Player2 NewPlayer3 = 20;

	// 아래는 리스트 이니셜라이저 문법이라고 합니다
	Player3 NewPlayer4 = Player3{ 20, 30 }; // << 선생님이 선호하는 방식
	// == Player3 NewPlayer4 = {20, 30};

	// Player::TestFunction() << 불가능, 전역변수처럼 사용할 수 없음

	// class의 멤버함수는 무조건 객체를 필요로 한다
	// 하지만 이 제약에서 벗어난 함수가 2종이 존재함
	// 1. 생성자 : 생성자는 객체를 만들어내는 전역함수
	// 생성자는 기본적으로 함수로 인식됨
	NewPlayer.TestFunction();
}
