// 080_TypeDefEx


#include <iostream>
typedef int MYINT, * MYTEST;

// C의 문법을 거의 다 그대로 C++에서 사용할 수 있다.
// 그렇다고 C++는 C를 포함한다?? XXXX (서로 완전히 다른 언어임, 약간 형님 동생사이?? 로 볼순있음)

// 문법적으로 C의 스타일을 거의 다 사용할 수 있다 (99버전 C??, 최신은 C17)

// C에서는 구조체가 있음 (C++의 구조체와의 차이점은 멤버함수를 넣을 수 없다)
struct __tagPlayer
{
	int HP;
	int Att;
};

typedef struct __tagPlayer Player;

// == 위의 문법을 합쳐서 나온게
//typedef struct __tagPlayer
//{
//	int HP;
//	int Att;
//} Player, *PPlayer;

int main()
{
	{
		// 아래문법을 C에서는 사용못함
		// Player NewPlayer;
		struct __tagPlayer NewPlayer; // << C에서는 struct를 생략할수가 없었음 

		// 너무 귀찮으니까 나온 문법이 typedef
		Player NewPlayer1;
	}
	int* Ptr0 = nullptr;
	// typedef에 *붙이면 포인터를 typedef하는 것
	MYTEST Ptr1 = nullptr;
}