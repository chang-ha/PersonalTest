// 032_Switch


// switch문 꿀팁 swi + Tab은 자동완성
//switch (switch_on)
//{
//default:
//	break;
//}
// if는 (메모리)영역이 참인지 거짓인지를 판단해서 코드를 실행해주는 조건문
// switch는 (메모리)영역과 완전히 같은 "상수 메모리"가 있는지 비교해주는 조건문
#include <iostream>
int main()
{
	int Value = 0;

	// case에는 상수 메모리만 올 수 있다.
	// int check = 0;
	// ex) case check : << 변수(check)는 불가능
	// 예외) const int check = 0; << 이러면 상수항이라서 가능
	// case별로 겹치는 값은 올 수 없음 ex) case 1: ... case 2 : ... case 1 : ...
	switch (Value)
	{
	case 0:
		break;
	default:
		break;
	}

	// break는 빠져나오는 명령어
	// break 없을 시 빠져나가지 않고 계속 코드 실행함
	switch (Value)
	{
	case 0:
		printf_s("Value = 0");
	case 1:
		printf_s("Value = 1");
	case 2:
		printf_s("Value = 2");
	default:
		break;
	}

	// case안에서 변수 선언시 안에서 새로운 지역( { } ) 으로 분류해야함
	switch (Value)
	{
	case 0:
	{
		printf_s("Value = 0");
		break;
	}
	case 1:
	{
		printf_s("Value = 1");
		break;
	}
	case 2:
	{
		printf_s("Value = 2");
		break;
	}
	default:
		printf_s("Not Vaule");
		break;
	}

	char InputKey = 'a';
	switch (InputKey)
	{
	case 'a':
		break;
	case 'A':
		break;
	default:
		break;
	}

}
