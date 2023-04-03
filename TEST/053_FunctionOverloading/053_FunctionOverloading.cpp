// 053_FunctionOverloading


#include <iostream>
void Function()
{
	// 얘 이름은 Function
	printf_s("void Function()");
}

void Function(int _Value)
{
	// 얘 이름은 Function int
	printf_s("void Function(int Value)");
}

void Function(short _Value)
{
	// 얘 이름은 Function int
	printf_s("void Function(short Value)");
}

void Function(int _Value, int _Test)
{
	// 얘 이름은 Function int int
	printf_s("void Function(int Value, int Test)");
}

// 리턴값은 함수 오버로딩에 영향을 주지 않는다.
//int Function(int _Value, int _Test)
//{
//	// 얘 이름은 Function int int
//	printf_s("void Function(int Value, int Test)");
//	return 0;
//}

// 선생님은 이런 오버로딩을 좋아하진 않음
void Function(short _Value, int _Test)
{
	// 얘 이름은 Function short int
	printf_s("void Function(short Value, int Test)");
}

// 오버로딩은 함수이름은 같지만 뒤의 Parameter의 자료형이 다르면 다른 이름이 되버림
// Function int int / Function short int

// 함수라고 불리는 녀석들에게는 모두 적용됨

class Player
{
public:
	Player()
	{

	}
	Player(int _Value)
	{

	}
	Player(int _Value0, int _Value1)
	{

	}
};
int main()
{
	Function(10);

	// 아래는 뭐가 출력될지는 모름
	Function(10, 10);

	// 명확하게 해줘야함
	Function((int)10, 10);

	// 모호한 경우가 있음
	// char('a')는  Function int와 Function short모두 인자로 받아드릴수 있다.
	// 불명확한것 == 선생님이 극혐하심
	Function('a');

	Player NewPlayer0 = Player();
	Player NewPlayer1 = Player(10);
	Player NewPlayer2 = Player(10, 20);
}