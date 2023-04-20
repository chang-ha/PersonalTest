// 054_Declaration


#include <iostream>
//함수를 볼때 2가지로 구분해야함
// 1. 함수 선언
void Function()

// 2. 함수체
{
}

// 구현이라고 하는 문법은
// 선언과 함수체를 같이 놓은 문법을 구현된 함수라고 부릅니다.
// 그런데 함수 선언만 따로 놓을수가 있다.
// Test2는 Test0이 필요하고, Test1은 Test0이 필요하고, Test0은 Test2가 필요함
// 이렇게 함수가 많아지면 제어할수가 없어짐
// 그래서 선언을 분리하는 문법이 사용됨

// 이러이러한 함수가 있을거야
// 일단 믿고 호출하고 컴파일해줘
// 구현은 분명히 나중에 있을거야
void Test0();
void Test1();
void Test2();

// 전역함수의 경우에는 선언은 몇개를 해도 상관없음
// 결국 한개만 남겨두고 다 지움
void Test2();
void Test2();
void Test2();
void Test2();
void Test2();

// 클래스는 문법상 선언과 구현이 내부에서 혼재되어 있을수도 있고
// 아닐수도 있는 특이한 놈..
// 클래스 자체는 2개를 선언할 수 없습니다. 
// class Player, class Player 두개 선언 불가능
class Player
{
	// 일반적인 멤버변수는 이미 그자체로 선언이면서 구현입니다.
	// 따로 실체를 둘 필요가 없다.
public:
	int Hp = 0;

public:
	// 클래스내부의 함수는 별개로 선언만 놔둘수 있다.
	Player();
	void Damage();

	// 클래스 내부에서 구현을 끝내버리면
	// 이미 구현을 끝낸것으로 판단
	// 외부에서는 구현 불가능 (똑같은 함수 2개 구현한 것으로 봄)
	void StatusRender()
	{

	}

	// static함수의 경우 멤버함수와 동일한 규칙을 적용
	static void GlobalFunction()
	{

	}

public:
	// static 멤버 변수의 경우에는 const가 붙으면 구현체를 따로 둘수가 없다.
	// 리터럴초기화가 가능
	// 상수로 생각해서 "코드영역에 위치"시키기 때문이다. << 내 의견 : sizeof해도 바이트수에 포함 안되더라 !!
	// 앞으로 Player::Value은 다 0으로 바꾼다.
	// 어차피 내가 지금 읽었을때 0이라는걸 읽었으니 이건 앞으로 절대 안바뀔거잖아?
	// 어차피 const, 그러니까 앞으로 Value가 보이면 그냥 0 (컴파일러 입장)
	static const int Value = 0;

	// static 멤버 변수의 경우에는 const가 안붙으면 데이터영역에 위치하게 되고
	// 리터럴초기화 불가능
	// 선언으로만 치게 되고 초기화 불가능
	// Player에 속한 static 전역변수인 Value1가 있을거야....
	static int Value1;
	// static int Value = 0;
};

// 실체를 가지려면 
// static const가 아닌 static
// Player에 속한 static 전역변수인 Value1이 여기있어!!!!!
int Player::Value1 = 10;


// 멤버함수의 FullName은 무조건
// 클래스명::함수명 으로 인식해야 한다.
Player::Player()
{
}

void Player::Damage()
{
}

//class Monster
//{
//	// 플레이어를 알아야 플레이어를 쓰지
//	Player* NewPlayer;
//};
int main()
{
	// 이대로 사용하면 컴파일 에러발생
	// "확인할 수 없는 외부 참조"
	// 너가 선언만하고 실체를 만들지 않았어!!!!!!!!!!!!!!!
	// Test0의 실체가 없어
	Test0();

	Player NewPlayer = Player();
	// Test0();
	int Value = NewPlayer.Value1;


	// 메인의 입장에서는 함수안에 뭐가 있는지 중요하지 않음
	// 중요한건 함수의 리턴이 뭔지가 중요함
	// 리턴값이 몇 바이트인지 알아야 메모리영역을 할당해놓기 때문에



}

// 구현부는 보통 main 아래 놔둠
//void Test0()
//{
//	Test2();
//}
void Test1()
{
	Test0();
}
void Test2()
{
	Test0();
}
