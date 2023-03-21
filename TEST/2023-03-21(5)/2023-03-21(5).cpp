// 금일 강의 내용 : class

#include <iostream>

// 학원의 객체지향을 배운다는 구성
//   => 나는 뭘 만들고 싶다.
//     => 클래스로 만들어
//       => 선생님에게 피드백을 받는다.
// C++에서 클래스는 모든것을 만들수 있는 문법입니다.
// int도 내가 클래스를 만드는 개념과 다르지 않다.


// 플레이어를 만들었음 << 이게 기본
// 이제 플레이어는 무엇을 할 수 있지???
// 아래는 사용자 정의 자료형중 하나입니다.
// 플레이어는 이러이러한 존재야.
class Player
{
	// 2가지를 가지고 있습니다
	// 1. 속성
	// 2. 행동

	
	// 속성 (보통 명사)
	// 속성 : 행동은 아니지만 가지고 있는 특성임
	// ex) 카리스마, 매력 등 수치로 표한가능하다
	// ex) 속력이 빠르다, 단단하다 등 
	// 아래를 멤버변수라고 한다.
	// 내부에서 변수를 선언함으로서 표현할 수 있다.
	const char* const Name = "Player";
	int Att; // 공격력
	int HP; // 체력

	// 행동 (보통 동사)
	// 맞을 수 있어야함
	// 뛸 수 있어야함
	// Player의 상태를 표현준다 등등
	// 함수로 표현된다
	void Run()
	{

	}

	void Damage(const int& _Damage())
	{

	}
	
	void StatusRender()
	{
		printf_s("%s의 스테이터스 -----------\n", Name);
		printf_s("공격력 : %d\n", Att);
		printf_s("체력 : %d\n", HP);
		printf_s("---------------------\n");
	}
};

// 자료형 << 최상위 개념
// 기본자료형 << int bool 등등
// 사용자정의자료형 << 내가 만드는 Player, Monster 등등... 모든 것을 표현할 수 있다.
int main()
{
	// 개념을 생각하고 개념을 class로 정의 내리고 NewPlayer가 객체입니다.
	// 변수 선언과 유사하다 (int도 사실은 객체(기본클래스))
	Player NewPlayer0 = Player(); // << NewPlayer가 객체임
	Player NewPlayer1= Player();
	Player NewPlayer2 = Player();
	Player Arr[3];

	// ~ int Value;
	int Value = int();

	
	// 플레이어
	// -> 공격력, 체력


}
