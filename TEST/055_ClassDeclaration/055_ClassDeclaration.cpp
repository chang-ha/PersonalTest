// 055_ClassDeclaration


#include <iostream>
// 아래를 순환참조라고 합니다. (사용에 주의해야함)
// 순환참조의 해결방법은 선언과 구현의 철저한 분리 입니다.
// 그래서 Monster라는 클래스가 있을거야 믿고 써.
// 클래스 전방선언이라고 합니다.
// 내용은 나중에 알려줄게~
// 그런게 몇 가지 제약사항이 있다.
class Monster;
class Player
{
public:
	int Att = 10;
	int Hp = 100;
	// 이건 몬스터가 있을거야... 라는 뜻이 아니고
	// 몬스터를 알아야 한다.
	void Attack(Monster* _NewMonster);
	//{
	//	_NewMonster->Hp -= Att;
	//}

	// 제약 1. 전방선언을 해도 해결이 안되는 경우가 존재
	// 내부에서 Monster의 내용을 사용하게 되면
	//void Attack(Monster* _NewMonster);
	//{
	//  몬스터는 Hp라는 변수가 있어???
	//  몬스터의 크기는 얼마야??
	//  몬스터는 어떤 생성자를 가지고 있어???
	//  자세한 내용들은 알 수가 없음
	//  컴파일러가 해당 내용을 알아야함
	//	Monster->Hp -= Att;
	//}
	// 그래서 전방선언을 사용하면 내부 코드들도 다 전방선언한 뒤
	// 자세한 내용은 main아래에 놔둬야함

	// 아래는 왜 되는건가???
	// 몬스터안의 멤버함수, 멤버변수를 사용하지 않았음
	// 그저 8바이트 주소값을 받아서 외부로 8바이트주소값을 리턴하기만 되는 함수
	// 그래서 가능함
	Monster* Test(Monster* _NewMonster)
	{
		return _NewMonster;
	}

	// 그런데 아래는 안됨 (가평인자)
	// 왜??? Monster는 몇 바이트인데??????????
	// 함수의 리턴값의 크기를 알 수가 없음.
	// Monster의 크기는 뭐에 의해서 결정이 되지???
	// 멤버 변수들의 개수와 종류로 결정된다.
	Monster Test2(Monster _NewMonster)
	{
		return _NewMonster;
	}
};

class Player;
class Monster
{
public:
	int Att = 10;
	int Hp = 100;
	void Damage(Player* _NewPlayer);
	//{
	//	_NewPlayer->Hp -= Att;
	//}
};
int main()
{
	Player NewPlayer;
	Monster NewMonster;

	NewPlayer.Attack(&NewMonster);
	NewMonster.Damage(&NewPlayer);
}

void Player::Attack(Monster* _NewMonster)
{
	_NewMonster->Hp -= Att;
}

void Monster::Damage(Player* _NewPlayer)
{
	_NewPlayer->Hp -= Att;
}