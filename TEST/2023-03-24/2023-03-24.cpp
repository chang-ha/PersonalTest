// 금일 강의 내용 : 보이지 않는 메모리 할당

#include <iostream>

class Number
{
private:
	int Value = 0;
public:
	Number& operator+=(int _Value)
	{
		Value += _Value;
		return *this; 
	}
	Number& operator++()
	{
		Value += 1;
		return *this;
	}
	int operator++(int)
	{
		int nResult = Value;
		Value += 1;
		return 0;
	}
};
int Test()
{
	return 10;
}
int main()
{
	{
		int Value = 0;
		// Test의 return값인 10을 담을 보이지 않는 4바이트가 존재함
		// return값을 메인이 받아야 하기 때문에
		// 하지만 그 보이지 않는 4바이트는 수정할 수 없음
		// 사용만 가능함 << const 와 유사함(수정은 못하고 사용만 가능)
		// 문법적으로 정해져 있음
		// ex)
		// Test() = 20; << 불가능 (Test의 return값인 10을 조작하는 행위는 불가능)
		//  (Value + 10) = 10; << 불가능
		// 그럼 (Value += 10) = 10; 은 왜 되는건가??? << 연산자의 결과값이 자기 자신을 리턴하기 때문에
		// ++Value = 10 도 동일함 << 전위함수도 자기 자신을 리턴
		// Value++ << 후위는 불가능 << 후위의 특이한 점 << 후위는 인자가 필요한 함수인데 인자가 없어도 사용가능
		// 전위랑 후위의 구분을 위해 후위는 인자를 받게 만들어 놓긴 함(없어도 동작은 함)
		// 내 의견 : 포인터(*)랑 곱연산(*)을 구분하는 것과 유사함 << 연산자가 같은 모양이라서...
		// 위에 함수를 보면 전위가 스택하나를 덜 만듬 (전위가 좋은 이유)
		Number NewNumber;
		++Value = 10;
		//++NewNumber = 10;
	}
}


