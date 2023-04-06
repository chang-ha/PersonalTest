// 070_Define (매크로함수)

#include <iostream>

// #define TEN 10;
#define TEN 10

// 함수형 define
// 문제점 << 컴파일러가 문법검사를 안해줘서 에러가 나도 모름 (무식 그 자체)
// 무조건 그냥 복붙
#define PLUS(VALUE) VALUE + VALUE
// 인자 여러개도 가능
//define PLUS(VALUE1, VALUE2) VALUE1 + VALUE2

// 함수의 경우에는 일반적으로 형에 대한 검사나
// 자료형에 의한 컴파일 체크를 한다.
void Test(int _Value)
{

}
int main()
{
	//TEN* TEN; == 10; * 10; ; << 이런꼴임 그래서 (;)를 하면 안됨
	int Value = TEN * TEN;

	// PLUS("AAAA");
	// "AAAA" + "AAAA";
}
